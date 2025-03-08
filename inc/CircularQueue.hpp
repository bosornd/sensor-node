#ifndef CIRCULARQUEUE_HPP
#define CIRCULARQUEUE_HPP

#include <mutex>

// S: type of Sensor data
// T: type of data in the queue
template <typename S, typename T>
class CircularQueue {
public:
    CircularQueue(const size_t& size) : head(0), tail(0), size(size) {
        buffer = new T[size];
    }

    virtual ~CircularQueue() {
        delete[] buffer;
    }

    bool isEmpty() const {
        return head == tail;
    }

    bool push(const S& sensorData) {
        buffer[tail] = sensorData;

        std::lock_guard<std::mutex> lock(mutex);
        tail = (tail + 1) % size;

        return true;
    }

    const T& top() const {
        return buffer[head];
    }

    bool pop() {
        if (isEmpty()) {
            return false;
        }

        std::lock_guard<std::mutex> lock(mutex);
        head = (head + 1) % size;

        return true;
    }

private:
    T* buffer;
    size_t head, tail, size;
    std::mutex mutex;
};

#endif // CIRCULARQUEUE_HPP