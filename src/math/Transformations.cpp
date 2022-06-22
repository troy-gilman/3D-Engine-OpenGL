#include "Transformations.hpp"

void Transformations::Translate(Matrix4f& matrix, const Vector3f& translation) {
    matrix.SetValue(0, 3, translation.x);
    matrix.SetValue(1, 3, translation.y);
    matrix.SetValue(2, 3, translation.z);
}

