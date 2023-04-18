//
// Created by ADMIN on 4/18/2023.
//

#ifndef PRJ_1_WEIGHT_H
#define PRJ_1_WEIGHT_H


#include <cstddef>

template <typename T>
class weight {
public:
    // Constructor
    weight(size_t rows, size_t cols);

    // Index operator overload
    T& operator()(size_t row, size_t col);

    // Rows count returning method
    size_t numRows() const;

    // Cols count returning method
    size_t numCols() const;

private:
    size_t m_rows;  // Matrix rows count
    size_t m_cols;  // Matrix cols count
    T* m_data;      // Indicator to array which is storaging data
};

// Constructor implementation
template <typename T>
weight<T>::weight(size_t rows, size_t cols)
        : m_rows(rows), m_cols(cols) {
    m_data = new T[m_rows * m_cols];  // Memory alocation for matrix elements
}

// Index operator implementation
template <typename T>
T& weight<T>::operator()(size_t row, size_t col) {
    return m_data[row * m_cols + col];
}

// Implementation of numRows()
template <typename T>
size_t weight<T>::numRows() const {
    return m_rows;
}

// Implementation of numCols()
template <typename T>
size_t weight<T>::numCols() const {
    return m_cols;
}



#endif //PRJ_1_WEIGHT_H
