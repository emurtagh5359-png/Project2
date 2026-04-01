#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class ArrayStack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        // TODO
        data.push_back(value);
    }

    void pop() {
        // TODO
        if (data.empty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        data.pop_back();
    }

    T top() const {
        // TODO
        if (data.empty()) {
            std::cout << "Stack is empty" << std::endl;
            return T();
        }
        return data.back();
    }

    bool empty() const {
        // TODO
        return data.empty();
    }

    int size() const {
        // TODO
        return static_cast<int>(data.size());
    }
};

#endif
