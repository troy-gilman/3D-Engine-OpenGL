#include "Transformations.hpp"

void Transformations::Translate(Matrix4f& matrix, const Vector3f& translation) {
    matrix.AddValue(0, 3, translation.GetX());
    matrix.AddValue(1, 3, translation.GetY());
    matrix.AddValue(2, 3, translation.GetZ());
}

