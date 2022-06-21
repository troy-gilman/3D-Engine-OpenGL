#pragma once

class Matrix4f {
public:
    static unsigned int const SIZE = 4;
private:
    float m_Elements[SIZE * SIZE];

public:
    Matrix4f();
    ~Matrix4f();

    void SetValue(unsigned int row, unsigned int col, float value);
    void AddValue(unsigned int row, unsigned int col, float value);
    float GetValue(unsigned int row, unsigned int col) const;
    const float* GetAll() const;
    void SetIdentity();
    void SetOrtho(float left, float right, float bottom, float top, float near, float far);

};

Matrix4f operator* (const Matrix4f& m1, const Matrix4f& m2);