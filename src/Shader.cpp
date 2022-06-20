#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Shader.hpp"
#include "Renderer.hpp"

Shader::Shader(const string &filepath) 
    : m_FilePath(filepath), m_RendererID(0) {
    ShaderProgramSource source = ParseShader(filepath);
    m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
}

Shader::~Shader() {
    GLCall(glDeleteProgram(m_RendererID));
}

void Shader::Bind() const {
    GLCall(glUseProgram(m_RendererID));
}

void Shader::Unbind() const {
    GLCall(glUseProgram(0));
}

void Shader::SetUniform1i(const string& name, int v0) {
    int location = GetUnifromLocation(name);
    GLCall(glUniform1i(location, v0));
}

void Shader::SetUniform1f(const string& name, float v0) {
    int location = GetUnifromLocation(name);
    GLCall(glUniform1f(location, v0));
}

void Shader::SetUniform4f(const string& name, float v0, float v1, float v2, float v3) {
    int location = GetUnifromLocation(name);
    GLCall(glUniform4f(location, v0, v1, v2, v3));
}


ShaderProgramSource Shader::ParseShader(const string& filepath) {
    ifstream stream(filepath);
    if (!stream) {
        cout << "Unable to open file " << filepath << endl;
    }
    enum class ShaderType {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };
    string line;
    stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while (getline(stream, line)) {
        if (line.find("#shader") != string::npos) {
            if (line.find("vertex") != string::npos) {
                type = ShaderType::VERTEX;
            } else if (line.find("fragment") != string::npos) {
                type = ShaderType::FRAGMENT;
            }
        } else {
            ss[(int) type] << line << '\n';
        }
    }
    return {ss[0].str(), ss[1].str()};
}

unsigned int Shader::CompileShader(unsigned int type, const string& source) {
    GLCall(unsigned int id = glCreateShader(type));
    const char* src = source.c_str();
    GLCall(glShaderSource(id, 1, &src, nullptr));
    GLCall(glCompileShader(id));
    // Error Handling
    int result;
    GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
    if (result == GL_FALSE) {
        int length;
        GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
        char* message = (char*) alloca(length * sizeof(char));
        GLCall(glGetShaderInfoLog(id, length, &length, message));
        cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << endl;
        cout << message << endl;
        GLCall(glDeleteShader(id));
        return 0;
    }
    return id;
}

unsigned int Shader::CreateShader(const string& vertexShader, const string& fragmentShader) {
    GLCall(unsigned int program = glCreateProgram());
    GLCall(unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader));
    GLCall(unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader));
    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));
    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));
    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));
    return program;
}

int Shader::GetUnifromLocation(const string& name) {
    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end()) {
        return m_UniformLocationCache[name];
    }
    GLCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));
    if (location == -1) {
        cout << "Warning: uniform " << name << " doesn't exist!" << endl;
    }
    m_UniformLocationCache[name] = location;
    return location;
}