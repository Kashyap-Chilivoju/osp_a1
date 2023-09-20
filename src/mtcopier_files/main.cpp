#include "reader.h"
#include "writer.h"
#include <queue>
#include <ctime>
#include <iostream>
#include <atomic>
#include <chrono>

static std::queue<std::string> linesQueue;
static pthread_cond_t writerCondition = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t queueMutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char* argv[]) {
    std::atomic<bool> terminationFlag(false);

    if (argc != 4) {
        std::cerr << "Usage: ./mtcopier <numThreads> <inputFile> <outputFile>" << std::endl;
        return 1;
    }

    int numThreads = std::stoi(argv[1]);
    std::string inputFile = argv[2];
    std::string outputFile = argv[3];

    reader rdr;
    writer wrt;

    rdr.init(inputFile, numThreads, linesQueue, writerCondition, terminationFlag, queueMutex);
    wrt.init(outputFile, numThreads, linesQueue, writerCondition, terminationFlag, queueMutex);

    //clock_t start = clock();
    auto start = std::chrono::high_resolution_clock::now();
    rdr.run();
    auto readEnd = std::chrono::high_resolution_clock::now();
    wrt.run();
    auto writeEnd = std::chrono::high_resolution_clock::now();
    rdr.joinAll();
    //auto readerEnd = std::chrono::high_resolution_clock::now();
    wrt.joinAll();
    //clock_t end = clock();
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::chrono::duration<double> readerRunTime = readEnd - start;
    std::chrono::duration<double> writerRunTime = writeEnd - readEnd;
    std::chrono::duration<double> readerTime = readEnd - start;
    std::cout << "Total Time Elapsed: " << duration.count() << " Seconds" << std::endl;
    std::cout << "ReaderRunTime  Elapsed: " << readerRunTime.count() << " Seconds" << std::endl;
    std::cout << "writerRunTime Time Elapsed: " << writerRunTime.count() << " Seconds" << std::endl;
    std::cout << "readerTime Time Elapsed: " << readerTime.count() << " Seconds" << std::endl;


    pthread_cond_destroy(&writerCondition);
    pthread_mutex_destroy(&queueMutex);
    //clock_t duration = end - start;
    //int seconds = (int)duration / (double)CLOCKS_PER_SEC;
    //std::cout << "Time elapsed: " << seconds << " seconds" << std::endl;

    return 0;
}
