#include <Fibula/Graphics/Shader.hpp>

#include <glm/gtc/type_ptr.hpp>

using namespace Fibula::Graphics;

void Shader::enable() const
{

}

void Shader::disable() const
{

}

GLint Shader::getUniformLocation(const std::string &name)
{
    return glGetUniformLocation(this->id, name.c_str());
}


void Shader::setUniformMatrix4x4(const std::string &name, const glm::mat4x4 &matrix)
{
    float m[16] = {0.0f};
    const float *pMatrix= (const float*)glm::value_ptr(matrix);

    for (int i = 0; i < 16; ++i) {
        m[i] = pMatrix[i];
    }

    glUniformMatrix4fv(this->getUniformLocation(name), 1, GL_FALSE, m);
}

Shader::~Shader()
{

}
