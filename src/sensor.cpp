#include <iostream>

#include "Sensor.hpp"

Sensor::Sensor(CircularQueue<int, Data>& queue) : queue(queue) {}

void Sensor::init() {
    thread = std::thread(&Sensor::poll, this);
}

void Sensor::poll() {
    while (true) {
        int data;
        std::cin >> data;
        queue.push(data);
    }
}