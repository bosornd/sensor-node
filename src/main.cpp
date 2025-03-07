#include <iostream>

#include "sensor.hpp"

int main() {
    Sensor sensor;
    sensor.init();

    while (true) {
        sensor.poll();
    }

    return 0;
}