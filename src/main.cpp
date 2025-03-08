#include <iostream>

#include "sensor.hpp"
#include "SensorNode.hpp"

int main() {
    CircularQueue<int, Data> queue(5);
    SensorNode node(queue);
    Sensor sensor(queue);
    sensor.init();

    while (true) {
        // instead of rclcpp::spin_some(node);
        // thread sleep for 10ms
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        node.publish();
    }

    return 0;
}