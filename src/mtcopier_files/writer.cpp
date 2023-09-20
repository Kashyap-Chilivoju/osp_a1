#include "writer.h"


writer::writer() {}

writer::~writer() {
    if (file.is_open()) {
        file.close();
    }
}

void writer::init(const std::string &filename, int numThreads, std::queue<std::string> &linesQueue,
                  pthread_cond_t &writerCondition, std::atomic<bool> &terminationFlag, pthread_mutex_t& sharedMutex) {
    this->writerCondition = &writerCondition;
    this->linesQueue = &linesQueue;
    this->filename = filename;
    this->terminationFlag = &terminationFlag;
    this->numThreads = numThreads;
    this->sharedMutex = &sharedMutex;
    this->file.open(filename);
    if (!this->file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
    }
}

void writer::run() {

        for(int i=0;i<numThreads;i++) {
            pthread_t thread;
            if (pthread_create(&thread, nullptr, runner, this) != 0) {
                std::cerr << "Error creating thread" << std::endl;
                return;
            }
            threads.push_back(thread);
        }
}
void *writer::runner(void *arg) {
    writer *wrt = static_cast<writer *>(arg);
    std::string line;

    while (true) {
        pthread_mutex_lock(wrt->sharedMutex);

        while (wrt->linesQueue->empty() && !*(wrt->terminationFlag)) {
            pthread_cond_wait(wrt->writerCondition, wrt->sharedMutex);
        }

        if (wrt->linesQueue->empty() && *(wrt->terminationFlag)) {
            pthread_mutex_unlock(wrt->sharedMutex);
            pthread_exit(nullptr);
        }

        line = wrt->linesQueue->front();
        wrt->linesQueue->pop();
        wrt->file << line;

        pthread_mutex_unlock(wrt->sharedMutex);
    }


}





void writer::joinAll() {
    for (pthread_t thread : threads) {
        pthread_join(thread, nullptr);
    }
    threads.clear();
}

