#include "Vector3f.hpp"

Vector3f::Vector3f() {
    SetX(0);
    SetY(0);
    SetZ(0);
}

Vector3f::Vector3f(float x, float y, float z) {
    SetX(x);
    SetY(y);
    SetZ(z);
}

Vector3f::~Vector3f() {

}

void Vector3f::SetX(float x) {
    m_Elelemts[0] = x;
}

float Vector3f::GetX() const {
    return m_Elelemts[0];
}

void Vector3f::SetY(float y) {
    m_Elelemts[1] = y;
}

float Vector3f::GetY() const {
    return m_Elelemts[1];
}

void Vector3f::SetZ(float z) {
    m_Elelemts[2] = z;
}

float Vector3f::GetZ() const {
    return m_Elelemts[2];
}

const float* Vector3f::GetAll() const {
    return m_Elelemts;
}