#include "semaphore.h"

void Semaphore::Wait() {
    std::unique_lock<std::mutex> lock(mutex_);
    while (count_ == 0) {
        condition_.wait(lock);
    }
    count_--;
}

void Semaphore::Signal() {
    std::unique_lock<std::mutex> lock(mutex_);
    count_++;
    condition_.notify_one();
}
