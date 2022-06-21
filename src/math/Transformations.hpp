#pragma once

#include "Matrix4f.hpp"
#include "Vector3f.hpp"

class Transformations {
public:
    static void Translate(Matrix4f& matrix, const Vector3f& translation);
};

