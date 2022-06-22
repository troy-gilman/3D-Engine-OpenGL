#include "Test2D.hpp"
#include "../engine/Renderer.hpp"
#include "../vendor/imgui/imgui.h"

namespace test {
    Test2D::TestClearColor() {
        VertexBuffer vb(positions, 4 * 4 * sizeof(float));
        VertexBufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);
        IndexBuffer ib(indices, 6);
    }

    Test2D::~TestClearColor() {

    }

    void Test2D::OnUpdate(float deltaTime) {

    }

    void Test2D::OnRender() {
        GLCall(glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]));
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
    }

    void Test2D::OnImGuiRender() {
        ImGui::ColorEdit4("Clear Color", m_ClearColor);
    }
};