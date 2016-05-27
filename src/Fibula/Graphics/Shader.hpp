#ifndef FIBULA_SHADER_HPP
#define FIBULA_SHADER_HPP

#include <string>
#include <GL/glew.h>
#include <glm/mat4x4.hpp>

namespace Fibula {
    namespace Graphics {
        class Shader
        {
        protected:
            GLuint id;
            std::string vertexSourcePath;
            std::string fragmentSourcePath;

        public:
            Shader(const std::string &vertexSourcePath, const std::string &fragmentSourcePath)
                    : vertexSourcePath(vertexSourcePath), fragmentSourcePath(fragmentSourcePath)
            { }

            void bind() const;
            void unbind() const;

            int getUniformLocation(const std::string &name);

            void setUniform(const std::string &name, const float value);
            void setUniform(const std::string &name, const glm::vec2 &vector);
            void setUniform(const std::string &name, const glm::vec3 &vector);
            void setUniform(const std::string &name, const glm::mat3x3 &matrix);
            void setUniform(const std::string &name, const glm::mat4x4 &matrix);

            ~Shader();
        };
    }
}

#endif //FIBULA_SHADER_HPP
