#pragma once

class Vector3f {
private:
    static unsigned int const SIZE = 3;
    float m_Elelemts[SIZE];

public:
    Vector3f();
    Vector3f(float x, float y, float z);
    ~Vector3f();

    void SetX(float x);
    float GetX() const;
    void SetY(float y);
    float GetY() const;
    void SetZ(float z);
    float GetZ() const;

    const float* GetAll() const;
};