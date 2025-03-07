#include <iostream>

#include "sensor.hpp"

Data::Data(int data) : data(data) {}

Data::Data(const Data& other) : data(other.data) {}

Data& Data::operator=(int data) {
    std::cout << "Data processed" << std::endl;
    this->data = data;
    return *this;
}

Data& Data::operator=(const Data& other) {
    std::cout << "Data copied" << std::endl;
    data = other.data;
    return *this;
}

Data::operator int() const {
    return data;
}

Sensor::Sensor() : data_ready(false) {}

void Sensor::init() {
    publishThread = std::thread(&Sensor::publish, this);
}

int Sensor::getSensorData() {
    int data;
    std::cin >> data;
    return data;
}

void Sensor::poll() {
    data = getSensorData();

    std::lock_guard<std::mutex> lock(data_mutex);

    data_ready = true;
    data_cond.notify_one();
}

void Sensor::publish() {
    while(true){
        std::unique_lock<std::mutex> lock(data_mutex);
        data_cond.wait(lock, [this] { return data_ready; });

        // simulate as if it takes a long time.
        // sleep for 2 second
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "publish topic - " << data << std::endl;
        data_ready = false;
    }
}