#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <pthread.h>
#include <atomic>
class writer {
public:
    writer();
    ~writer();

    void init(const std::string &filename, int numThreads, std::queue<std::string> &linesQueue,
                      pthread_cond_t &writerCondition, std::atomic<bool> &terminationFlag, pthread_mutex_t &sharedMutex);
    void run();
    void joinAll();

private:
    std::ofstream file;
    std::string filename;
    int numThreads;
    std::vector<pthread_t> threads;
    pthread_mutex_t *sharedMutex;
    std::queue<std::string>* linesQueue;
    std::atomic<bool>* terminationFlag;
    pthread_cond_t* writerCondition; // Pointer to writer's condition variable
    void killThreads();
    static void* runner(void* arg);
};
