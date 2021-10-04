#pragma once

#include <initializer_list>
#include <iostream>
#include <string>

class EmptyStackError : public std::exception {
  public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Can't pop from empty stack";
    }
};

template <typename T> class Stack {
  private:
    T *array;
    int capacity = 100;
    int top = 0;

  public:
    Stack() { array = new T[capacity]; }
    ~Stack() {
        if (capacity != 0) {
            delete[] array;
        }
    }

    int size() { return top; }

    bool isEmpty() {
        if (size() == 0) {
            return true;
        }
        return false;
    }

    void push(T val) {
        if (top == capacity) {
            T *oldArray = array;
            array = new T[capacity * 2];
            for (int i = 0; i < capacity; i++) {
                array[i] = oldArray[i];
            }
            capacity *= 2;
            delete[] oldArray;
        }
        array[top] = val;
        top += 1;
    }
    T pop() {
        if (isEmpty()) {
            throw EmptyStackError();
        } else {
            top--;
        }
        return array[top];
    }

    T operator[](int i) { return array[i]; }

    T top_elem() { return array[top - 1]; }
};