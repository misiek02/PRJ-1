//
// Created by ADMIN on 14.03.2023.
//

#ifndef PRJ_1_ARRAY_H
#define PRJ_1_ARRAY_H
#include <iostream>

template<typename T>
class Array {
private:
    T* arr;
    int size;
public:
    Array(int size = 10) {
        this->size = size;
        arr = new T[size];
    }

    ~Array() {
        delete[] arr;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Index out of range!" << std::endl;
            exit(1);
        }
        return arr[index];
    }

    int getSize() {
        return size;
    }

    void add(T element) {
        if (size == 0) {
            arr = new T[1];
            arr[0] = element;
            size = 1;
        } else {
            T* temp = new T[size + 1];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            temp[size] = element;
            delete[] arr;
            arr = temp;
            size++;
        }
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Index out of range!" << std::endl;
            exit(1);
        }
        T* temp = new T[size - 1];
        for (int i = 0, j = 0; i < size; i++) {
            if (i != index) {
                temp[j++] = arr[i];
            }
        }
        delete[] arr;
        arr = temp;
        size--;
    }

    int find(T element) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;
    }
};

#endif //PRJ_1_ARRAY_H
