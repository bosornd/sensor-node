#ifndef SENSORNODE_HPP
#define SENSORNODE_HPP

#include "Data.hpp"
#include "CircularQueue.hpp"

// it extends rclcpp::Node
class SensorNode {
public:
    SensorNode(CircularQueue<int, Data>& queue);

    bool publish();

private:
    CircularQueue<int, Data>& queue;
};

#endif // SENSORNODE_HPP