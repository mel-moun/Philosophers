# philosophers 🍽️

## Overview 📝

`philosophers` is a C project that simulates the classic "Dining Philosophers Problem" using threads and mutexes. The objective of this project is to implement a solution that ensures the philosophers can dine without deadlock and with minimal resource contention. This project helps students practice using threads and synchronization mechanisms in C, such as mutexes and condition variables.

The problem involves a group of philosophers sitting at a round table, where each philosopher thinks and occasionally picks up two chopsticks to eat. However, philosophers must avoid deadlock while eating, and each must be able to eat without indefinite waiting.

## Features 🌟

- Simulates the classic "Dining Philosophers Problem" with multiple philosophers and chopsticks.
- Each philosopher alternates between thinking and eating.
- Ensures that there is no deadlock and no starvation of philosophers.
- Uses threads and synchronization mechanisms (mutexes) to manage concurrent behavior.
- Customizable number of philosophers and time parameters.

## Problem Constraints 🔒

- Each philosopher must think for a certain period of time before eating.
- Philosophers need two chopsticks to eat, and the chopsticks are shared resources.
- A philosopher should not hold both chopsticks for an indefinite amount of time.
- The program must ensure that no philosopher is starved and that deadlock is avoided.
- The program must stop when all philosophers have eaten a specific number of times or after a certain time.
