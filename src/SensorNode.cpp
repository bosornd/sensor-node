#include <iostream>

#include "SensorNode.hpp"

SensorNode::SensorNode(CircularQueue<int, Data>& queue) : queue(queue) {}

bool SensorNode::publish() {
    if (queue.isEmpty()) {
        return false;
    }

    // simulate as if it takes a long time.
    // sleep for 2 second
    std::this_thread::sleep_for(std::chrono::seconds(2));

    const Data& data = queue.top();
    std::cout << "publish topic " << data << std::endl;
    queue.pop();

    return true;
}