# Multi-threaded-Producer-Consumer-Counter

## Introduction

This README details the instructions for compiling and running the "myCounter" program, a C-based implementation focusing on multi-threading, mutual exclusion, and condition variables.

## Learning Outcomes

By completing this assignment, you will understand:
- The concept of mutual exclusion and its importance in concurrent access to shared resources (MLO 2).
- APIs for creating and managing threads and their termination (MLO 4).
- The use and implementation of condition variables (MLO 4).

## Instructions

### Program Overview

The "myCounter" program demonstrates a Producer-Consumer approach using two threads:
- **Producer Thread:** The initial thread of the program.
- **Consumer Thread:** Created within the program.

Both threads communicate and synchronize their operations, specifically around the incrementation and monitoring of a shared counting variable.

### Shared Resources and Synchronization

The program uses the following shared resources:
- **Mutex (`myMutex`):** For ensuring mutual exclusion.
- **Condition Variables (`myCond1` and `myCond2`):** For thread synchronization.
- **Counting Variable (`myCount`):** A shared variable incremented from 0 to 10.

### Output Specifications

The program's output is strictly defined as follows:
- **Program Start:** `PROGRAM START`
- **Consumer Thread Creation:** `CONSUMER THREAD CREATED`
- **Count Value Change:** `myCount: <PREVIOUS#> -> <NEW#>`
- **Mutex Unlock:** `<THREAD>: myMutex unlocked`
- **Mutex Lock:** `<THREAD>: myMutex locked`
- **Condition Variable Wait:** `<THREAD>: waiting on <CONDITION VAR>`
- **Condition Variable Signal:** `<THREAD>: signaling <CONDITION VAR>`
- **Program End:** `PROGRAM END`

## Compilation and Execution Instructions

### Environment Setup

1. Access the Oregon State University OS servers.

### Compiling the Code

1. Navigate to the directory containing the unzipped file.
2. Compile the program using:
   ```
   gcc -std=c99 main.c -o main -pthread
   ```

### Running the Program

1. Start the program:
   ```
   ./main
   ```
2. Follow the on-screen prompts as the program executes.

## Additional Notes

- Ensure all the naming conventions for mutex, condition variables, and the counting variable are followed as specified.
- The output format should strictly match the given specifications for successful execution.
- The program demonstrates basic principles of multi-threading and synchronization in C.

