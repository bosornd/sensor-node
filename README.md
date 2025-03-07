# sensor-node

## Overview

`sensor-node` is a simple C++ program that simulates a sensor node. The program initializes a sensor, continuously polls for data input, and publishes the data to a topic.

![Flow Diagram](img/flow.png)

Two threads are running concurrently and share data. While pub-thread is using the data, the main-thread may overwrite the data. A race condition occurs as shown below.

```
$ sensor-node
1
Data processed
2
Data processed
publish topic - 2
3
Data processed
publish topic - 3
publish topic - 3
```

## Project Structure

- `CMakeLists.txt`: CMake configuration file for building the project.
- `inc/sensor.hpp`: Header file for the `Sensor` class.
- `src/main.cpp`: Main entry point of the program.
- `src/sensor.cpp`: Implementation of the `Sensor` class.

## Building the Project

To build the project, you need to have CMake and a C++ compiler installed. Follow these steps:

1. Create a build directory:
    ```sh
    mkdir build
    cd build
    ```

2. Run CMake to configure the project:
    ```sh
    cmake ..
    ```

3. Build the project:
    ```sh
    cmake --build .
    ```

## Running the Program

After building the project, you can run the executable:

```sh
./sensor-node
```