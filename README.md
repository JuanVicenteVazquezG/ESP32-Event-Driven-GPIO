# ESP32 Event-Driven GPIO Controller

**Resilient Digital Input System for Industrial Environments.**

This repository implements a High-Performance HAL (Hardware Abstraction Layer) for ESP32 GPIO management, focusing on strict C++20 standards and rigorous engineering practices.

## Core Features

* **Industrial Resilience:** Hybrid debouncing architecture combining physical RC filters with software-based hysteresis to eliminate noise in harsh electrical environments.
* **Low-Latency ISRs:** Interrupt Service Routines marked with `IRAM_ATTR` to ensure execution from RAM, minimizing latency and preventing cache misses during critical events.
* **Autonomous Recovery:** Self-healing logic designed to operate independently of the USB/Serial interface, ensuring system stability even after communication bus failures.
* **Non-Blocking Architecture:** Fully asynchronous event handling to maximize CPU cycles for RTOS tasks or networking stacks.

## Tech Stack
* **Language:** C++20 (GCC 13+)
* **Hardware:** ESP32 (Xtensa LX6)
* **Pattern:** Event-Driven / RAII / volatile states
