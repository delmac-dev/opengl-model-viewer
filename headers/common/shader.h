#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

using std::string;

string get_file_contents(const char* file);

class Shader {
    public:
        GLuint ID;
        Shader();
        Shader(const char* vertexFile, const char* fragmentFile);

        void Use() const;
        void Clean() const;

        void SetInt(const std::string& name, int value) const;
        void SetVec3(const std::string &name, const glm::vec3 &value) const;
        void SetVec3(const std::string &name, float x, float y, float z) const;
        void SetMat4(const std::string &name, const glm::mat4 &mat) const;
    
    private:
        void CheckErrors(GLuint shader, string type);
};

#endif