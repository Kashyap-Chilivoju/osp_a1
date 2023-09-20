#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <pthread.h>
#include <atomic>
class reader {
public:
    reader();
    ~reader();
    struct ThreadData {
        int threadPosition;
        std::streampos start;
        std::streampos end;
        std::queue<std::string> localQueue;
        // You may want to include other shared resources here
        reader* owner; // Reference to the reader object itself
    };
    void init(const std::string& filename, int numThreads, std::queue<std::string>& linesQueue, pthread_cond_t& writerCondition, std::atomic<bool>& terminationFlag, pthread_mutex_t& queueMutex);
    void run();
    void joinAll();

private:
    std::ifstream file;
    std::string filename;
    int numThreads;
    pthread_mutex_t *sharedMutex;
    std::vector<pthread_t> threads;
    std::atomic<bool>* terminationFlag;
    std::atomic<int> queuePosition;
    pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
    int activeReaders;
    std::queue<std::string>* linesQueue; // Queue to store the lines
    pthread_cond_t* writerCondition; // Pointer to writer's condition variable

    bool readLine(std::string& line);

    static void* runner(void* arg);
};
