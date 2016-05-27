#include <Fibula/Graphics/Shader.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace Fibula::Graphics;

void Shader::bind() const
{
    glUseProgram(this->id);
}

void Shader::unbind() const
{
    glUseProgram(0);
}

int Shader::getUniformLocation(const std::string &name)
{
    return glGetUniformLocation(this->id, name.c_str());
}

void Shader::setUniform(const std::string &name, const float value)
{
    glUniform1f(this->getUniformLocation(name), value);
}

void Shader::setUniform(const std::string &name, const glm::mat4x4 &matrix)
{
    glUniformMatrix4fv(this->getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::setUniform(const std::string &name, const glm::vec2 &vector)
{
    glUniform2f(this->getUniformLocation((name)), vector.x, vector.y);
}

void Shader::setUniform(const std::string &name, const glm::vec3 &vector)
{
    glUniform3f(this->getUniformLocation((name)), vector.x, vector.y, vector.z);
}

void Shader::setUniform(const std::string &name, const glm::mat3x3 &matrix)
{
    glUniformMatrix3fv(this->getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

Shader::~Shader()
{
    glDeleteProgram(this->id);
}


