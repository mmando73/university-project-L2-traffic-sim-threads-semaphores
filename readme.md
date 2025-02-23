# Traffic Simulator

## Overview
This project is a traffic management simulator developed as part of an operating systems course. The simulator models vehicle flow at the roundabout of "Souvenir Français" in Pau city, utilizing various scheduling algorithms to manage autonomous vehicles at a roundabout using threads and semaphores.

## Objectives
The main objective of this project is to design a prototype scheduling system capable of effectively managing a flow of autonomous vehicles through a roundabout, ensuring that only one vehicle enters the roundabout at any given time, even when multiple vehicles arrive simultaneously at different entries.

## Features
- **Multithreading:** Each vehicle is handled as a separate thread to simulate independent vehicle actions (arrival, traversal, and exit).
- **Semaphore Control:** A semaphore mechanism is used to prevent collisions and ensure that the roundabout can only accommodate one vehicle at a time.
- **Scheduling Algorithms:** Implements both First Come, First Served (FCFS) and Shortest Job First (SJF) scheduling, with or without priority considerations.
- **Command Line Interface:** A simple CLI is used to input vehicle sequences and select scheduling options.
- **Gantt Chart Visualization:** Visual output via a Gantt chart to represent the scheduling and order of vehicle traversal.

## Compilation and Usage
### Prerequisites
Ensure you have GCC and make installed on your system to compile and run this project.

### Compiling the Project
Navigate to the project directory and use the following make command:
```
make
```

### Running the Simulator
To run the simulator, use the following command:
```
./bin/traffic_simulator -o [scheduler_option] -p [priority_option] [vehicle_sequence]
```

Where:
- `-o [scheduler_option]`: `0` for SJF, `1` for FCFS (default is `1`).
- `-p [priority_option]`: `0` for no priority, `1` for priority handling (default is `0`).
- `[vehicle_sequence]`: A string representing the sequence of vehicles (e.g., `A2c4E`).

### Examples
Run the simulator with the FCFS scheduler and priority handling:
```
./bin/traffic_simulator -o 1 -p 1 A2C4E
```

## Directory Structure
- **/src/**: Contains the source files of the project.
- **/include/**: Contains the header files.
- **/bin/**: Contains the executable file and object files.
- **/tests/**: Test files and test documentation.