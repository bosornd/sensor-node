#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <thread>

#include "Data.hpp"
#include "CircularQueue.hpp"

class Sensor {
public:
    Sensor(CircularQueue<int, Data>& queue);
    void init();

private:
    void poll();

private:
    CircularQueue<int, Data>& queue;
    std::thread thread;
};

#endif // SENSOR_HPP