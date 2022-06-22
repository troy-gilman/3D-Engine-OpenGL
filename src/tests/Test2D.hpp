#pragma once

#include "Test.hpp"
#include "../engine/VertexArray.hpp"

namespace test {
    class Test2D : public Test {
    private:
        float positions[] = {
            -50.0f, -50.0f, 0.0f, 0.0f,
             50.0f, -50.0f, 1.0f, 0.0f,
             50.0f,  50.0f, 1.0f, 1.0f,
            -50.0f,  50.0f, 0.0f, 1.0f
        }

        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        }

        VertexArray va;

    public:
        TestClearColor();
        ~TestClearColor();

        void OnUpdate(float deltaTime) override;
        void OnRender() override;
        void OnImGuiRender() override;
    };
}