#include "Transformations.hpp"

void Transformations::Translate(Matrix4f& matrix, const Vector3f& translation) {
    matrix.AddValue(0, 3, translation.x);
    matrix.AddValue(1, 3, translation.y);
    matrix.AddValue(2, 3, translation.z);
}

