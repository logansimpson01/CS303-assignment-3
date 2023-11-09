#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <deque>
#include <cstddef> 
#include <stdexcept> // for std::out_of_range

template <typename T>
class Queue {
private:
    std::deque<T> data;

public:
    // Inserts a new element at the rear of the queue
    void enqueue(const T& value) {
        data.push_back(value);
    }

    // Removes the front element of the queue and returns it
    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        T value = data.front();
        data.pop_front();
        return value;
    }

    // Returns the front element present in the queue without removing it
    T& front() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data.front();
    }

    // Checks if the queue is empty
    bool isEmpty() const {
        return data.empty();
    }

    // Returns the total number of elements present in the queue
    size_t size() const {
        return data.size();
    }
};

#endif // QUEUE_H
