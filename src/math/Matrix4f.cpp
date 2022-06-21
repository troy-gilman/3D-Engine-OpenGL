#include "Matrix4f.hpp"

Matrix4f::Matrix4f() {
    SetIdentity();
}

Matrix4f::~Matrix4f() {

}

void Matrix4f::SetValue(unsigned int row, unsigned int col, float value) {
    m_Elements[col * SIZE + row] = value;
}

void Matrix4f::AddValue(unsigned int row, unsigned int col, float value) {
    SetValue(row, col, GetValue(row, col) + value);
}

float Matrix4f::GetValue(unsigned int row, unsigned int col) const {
    return m_Elements[col * SIZE + row];
}

const float* Matrix4f::GetAll() const {
    return m_Elements;
}

void Matrix4f::SetIdentity() {
    for (unsigned int col = 0; col < SIZE; col++) {
        for (unsigned int row = 0; row < SIZE; row++) {
            if (col == row) {
                SetValue(row, col, 1);
            } else {
                SetValue(row, col, 0);
            }
        }
    }
}

void Matrix4f::SetOrtho(float left, float right, float bottom, float top, float near, float far) {
    SetIdentity();
    SetValue(0, 0, 2 / (right - left));
    SetValue(1, 1, 2 / (top - bottom));
    SetValue(2, 2, -2 / (far - near));
    SetValue(0, 3, -(right + left) / (right - left));
    SetValue(1, 3, -(top + bottom) / (top - bottom));
    SetValue(2, 3, -(far + near) / (far - near));
}

Matrix4f operator* (const Matrix4f& m1, const Matrix4f& m2) {
    Matrix4f result;
    for (unsigned int row = 0; row < Matrix4f::SIZE; row++) {
        for (unsigned int col = 0; col < Matrix4f::SIZE; col++) {
            float value = 
                m1.GetValue(row, 0) * m2.GetValue(0, col) +
                m1.GetValue(row, 1) * m2.GetValue(1, col) +
                m1.GetValue(row, 2) * m2.GetValue(2, col) +
                m1.GetValue(row, 3) * m2.GetValue(3, col);
            result.SetValue(row, col, value);
        }
    }
    return result;
}