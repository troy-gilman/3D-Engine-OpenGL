#pragma once

#include <string>
#include <unordered_map>

#include "../math/Matrix4f.hpp"
using namespace std;


struct ShaderProgramSource {
    string VertexSource;
    string FragmentSource;
};

class Shader {
private:
    string m_FilePath;
    unsigned int m_RendererID;
    unordered_map<string, int> m_UniformLocationCache;
public:
    Shader(const string& filepath);
    ~Shader();

    void Bind() const;
    void Unbind() const;

    // Set Uniforms
    void SetUniform1i(const string& name, int v0);
    void SetUniform1f(const string& name, float v0);
    void SetUniform4f(const string& name, float v0, float v1, float v2, float v3);
    void SetUniformMat4f(const string& name, const Matrix4f& matrix);

private:
    ShaderProgramSource ParseShader(const string& filepath);
    unsigned int CompileShader(unsigned int type, const string& source);
    unsigned int CreateShader(const string& vertexShader, const string& fragmentShader);
    int GetUnifromLocation(const string& name);
};