#pragma once

#include "Test.hpp"

#include <functional>
#include <vector>
#include <iostream>

namespace test {
    class TestMenu : public Test {
    private:
        Test*& m_CurrentTest;
        std::vector<std::pair<std::string, std::function<Test*()>>> m_Tests;

    public:
        TestMenu(Test*& currentTestPointer);
        void OnImGuiRender() override;
        
        template<typename T>
        void RegisterTest(const std::string& name) {
            std::cout << "Registering Test: " << name << std::endl;
            m_Tests.push_back(std::make_pair(name, [](){ return new T(); }));
        }
    };
}