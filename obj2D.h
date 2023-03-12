#pragma once

#include <string>
#include <cmath>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace obj2D
{
    Mesh* CreateHead(const std::string &name, glm::vec3 centerPoint, float length, glm::vec3 color);
    Mesh* CreateBody(const std::string &name, glm::vec3 leftBottomCorner, glm::vec3 color);
    Mesh* CreateLeftWing(const std::string &name, glm::vec3 leftBottomCorner, glm::vec3 color);
    Mesh* CreateRightWing(const std::string &name, glm::vec3 leftBottomCorner, glm::vec3 color);
    Mesh* CreateBeak(const std::string &name, glm::vec3 leftBottomCorner, glm::vec3 color);
    Mesh* CreateBullet(const std::string &name, glm::vec3 leftBottomCorner, glm::vec3 color);
    Mesh* CreateRectangle(const std::string &name, glm::vec3 leftBottomCorner, glm::vec3 color, bool fill, int length, int width);
    Mesh* CreateLetterL(const std::string &name, glm::vec3 leftBottomCorner, glm::vec3 color);
    Mesh* CreateLetterS(const std::string &name, glm::vec3 leftBottomCorner, glm::vec3 color);
    Mesh* CreateLetterE(const std::string &name, glm::vec3 leftBottomCorner, glm::vec3 color);
    Mesh* CreateLetterW(const std::string &name, glm::vec3 leftBottomCorner, glm::vec3 color);
    Mesh* CreateLetterI(const std::string &name, glm::vec3 leftBottomCorner, glm::vec3 color);
    Mesh* CreateLetterN(const std::string &name, glm::vec3 leftBottomCorner, glm::vec3 color);
}
