#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <thread>
#include <mutex>
#include <condition_variable>

class Data {
public:
    Data(int data = 0);
    Data(const Data& other);
    Data& operator=(int data);
    Data& operator=(const Data& other);
    operator int() const;

private:
    int data;
};

class Sensor {
public:
    Sensor();
    void init();

    void poll();
    void publish();

private:
    int getSensorData();

private:
    Data data, data_for_share;

    std::thread publishThread;

    bool data_ready;
    std::mutex data_mutex;
    std::condition_variable data_cond;
};

#endif // SENSOR_HPP