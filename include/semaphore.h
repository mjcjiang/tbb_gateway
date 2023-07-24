/**
 * @file semaphore.h
 * @brief semaphore, thread commulication tool
 *
 * @date 2023-07-20
 */

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <mutex>
#include <condition_variable>

class Semaphore {
 public:
    static Semaphore& GetInstance() {
        static Semaphore instance;
        return instance;
    }

    // fobidden the copy constructor and copy assignment constructor
    Semaphore(const Semaphore&) = delete;
    Semaphore& operator=(const Semaphore&) = delete;

    void Wait();
    void Signal();
 private:
    Semaphore() {}

    static Semaphore instance;
 private:
    std::mutex mutex_;
    std::condition_variable condition_;
    int count_ = 0;
};

#endif //SEMAPHORE_H
