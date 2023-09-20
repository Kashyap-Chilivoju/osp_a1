#include "reader.h"


reader::reader() {}

reader::~reader() {
    if (file.is_open()) {
        file.close();
    }
}

void reader::init(const std::string& filename, int numThreads, std::queue<std::string>& linesQueue, pthread_cond_t& writerCondition, std::atomic<bool>& terminationFlag, pthread_mutex_t& sharedMutex) {
    this->writerCondition = &writerCondition;
    this->linesQueue = &linesQueue;
    this->numThreads = numThreads;
    this->file.open(filename);
    this->filename= filename;
    this->sharedMutex = &sharedMutex;
    this->terminationFlag = &terminationFlag;
    if (!this->file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
    }
}

void reader::run() {
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    std::streampos sectionSize = fileSize / numThreads;
    activeReaders = numThreads;
    queuePosition=0;
    for (int i = 0; i < numThreads; ++i) {
        ThreadData* data = new ThreadData;
        data->threadPosition = i;
        data->start = i * sectionSize;
        data->end = (i == numThreads - 1) ? fileSize : data->start + sectionSize;
        data->owner = this; // Set the reader object itself

        pthread_t thread;
        if (pthread_create(&thread, nullptr, runner, data) != 0) {
            std::cerr << "Error creating thread" << std::endl;
            return;
        }
        threads.push_back(thread);
    }
}

bool reader::readLine(std::string &line) {
    if (!std::getline(file, line)) {
        return false;
    }
    return true;
}

void* reader::runner(void* arg) {
    ThreadData* data = static_cast<ThreadData*>(arg);
    reader* owner = data->owner;

    std::ifstream localFile(owner->filename, std::ios::in);
    if (!localFile.is_open()) {
        std::cerr << "Error opening file in thread" << std::endl;
        pthread_exit(nullptr);
    }


    localFile.seekg(data->start, std::ios::beg);

    const size_t bufferSize = 4096; // tuneable variable according to input file, I am just going with recommended default
    char buffer[bufferSize];
    std::string line;
    while (localFile.tellg() < data->end) {
        localFile.read(buffer, std::min(bufferSize, static_cast<size_t>(data->end - localFile.tellg())));
        int bytesRead = static_cast<int>(localFile.gcount()); // Change here

        int startIndex = 0; // Change here
        int i;
        for (i = 0; i < bytesRead; ++i) {
            if (buffer[i] == '\n' || i == bytesRead - 1) {
                size_t length = (buffer[i] == '\n') ? (i - startIndex + 1) : (i - startIndex + 1);
                line.append(&buffer[startIndex], length);
                data->localQueue.push(line);
                line.clear();
                startIndex = i + 1;
            }
        }
        if (startIndex < bytesRead) {
            line.append(&buffer[startIndex], bytesRead - startIndex);
        }
    }



    pthread_mutex_lock(owner->sharedMutex);

    while (owner->queuePosition.load() != data->threadPosition) {
        pthread_cond_wait(&owner->condition, owner->sharedMutex);
    }


    while (!data->localQueue.empty()) {
        owner->linesQueue->push(data->localQueue.front());
        data->localQueue.pop();
    }

    owner->queuePosition.fetch_add(1);

    pthread_cond_broadcast(&owner->condition);
    pthread_cond_broadcast(owner->writerCondition);
    pthread_mutex_unlock(owner->sharedMutex);

    pthread_mutex_lock(owner->sharedMutex);
    owner->activeReaders--;
    if (owner->activeReaders == 0) {
        *(owner->terminationFlag) = true;
        pthread_cond_broadcast(owner->writerCondition);
    }
    pthread_mutex_unlock(owner->sharedMutex);

    delete data;
    pthread_exit(nullptr);
}



void reader::joinAll() {
    for (pthread_t thread: threads) {
        pthread_join(thread, nullptr);
    }

    threads.clear();
}
