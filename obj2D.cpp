#include "obj2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"

Mesh* obj2D::CreateHead(
    const std::string& name,
    glm::vec3 centerPoint,
    float length,
    glm::vec3 color)
{
    glm::vec3 center = centerPoint;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(center, color),
    };
    
    double aux = 2 * M_PI / 1000;
    for (int i = 0; i < 1000; i++)
    {
        vertices.push_back(VertexFormat(center + glm::vec3(length * cos(i * aux), length * sin(i * aux), 0), color));
    }

    Mesh* head = new Mesh(name);
    std::vector<unsigned int> indices;

    for (int i = 1; i < 1000; i++)
    {
        indices.push_back(0);
        indices.push_back(i);
        indices.push_back(i + 1);
    }
    indices.push_back(0);
    indices.push_back(1000);
    indices.push_back(1);

    head->InitFromData(vertices, indices);
    return head;
}

Mesh* obj2D::CreateBody(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    glm::vec3 color)
{
    glm::vec3 startPoint = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(startPoint, color),
        VertexFormat(startPoint - glm::vec3(40, 160, 0), color),
        VertexFormat(startPoint + glm::vec3(40, -160, 0), color)
    };

    Mesh* body = new Mesh(name);
    std::vector<unsigned int> indices = {0, 1, 2};

    body->InitFromData(vertices, indices);
    return body;
}

Mesh* obj2D::CreateLeftWing(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    glm::vec3 color)
{
    glm::vec3 startPoint = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(startPoint, color),
        VertexFormat(startPoint - glm::vec3(45, 0, 0), color),
        VertexFormat(startPoint - glm::vec3(5, 20, 0), color)
    };

    Mesh* leftWing = new Mesh(name);
    std::vector<unsigned int> indices = {0, 1, 2};

    leftWing->InitFromData(vertices, indices);
    return leftWing;
}

Mesh* obj2D::CreateRightWing(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    glm::vec3 color)
{
    glm::vec3 startPoint = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(startPoint, color),
        VertexFormat(startPoint + glm::vec3(5, -20, 0), color),
        VertexFormat(startPoint + glm::vec3(45, 0, 0), color)
    };

    Mesh* rightWing = new Mesh(name);
    std::vector<unsigned int> indices = {0, 1, 2};

    rightWing->InitFromData(vertices, indices);
    return rightWing;
}

Mesh* obj2D::CreateBeak(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    glm::vec3 color)
{
    glm::vec3 startPoint = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(startPoint, color),
        VertexFormat(startPoint + glm::vec3(10, 0, 0), color),
        VertexFormat(startPoint + glm::vec3(5, 25, 0), color)
    };

    Mesh* beak = new Mesh(name);
    std::vector<unsigned int> indices = {0, 1, 2};

    beak->InitFromData(vertices, indices);
    return beak;
}

Mesh* obj2D::CreateBullet(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    glm::vec3 color)
{
    glm::vec3 startPoint = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(startPoint, color),
        VertexFormat(startPoint + glm::vec3(10, 0, 0), color),
        VertexFormat(startPoint + glm::vec3(10, 30, 0), color),
        VertexFormat(startPoint + glm::vec3(0, 30, 0), color)
    };

    Mesh* bullet = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 0, 2, 3 };

    bullet->InitFromData(vertices, indices);
    return bullet;
}

Mesh* obj2D::CreateRectangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    glm::vec3 color,
    bool fill,
    int length,
    int width)
{
    glm::vec3 startPoint = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(startPoint, color),
        VertexFormat(startPoint + glm::vec3(length, 0, 0), color),
        VertexFormat(startPoint + glm::vec3(length, width, 0), color),
        VertexFormat(startPoint + glm::vec3(0, width, 0), color)
    };

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill)
        rectangle->SetDrawMode(GL_LINE_LOOP);
    else
    {
        indices.push_back(0);
        indices.push_back(2);
    }
    
    rectangle->InitFromData(vertices, indices);
    return rectangle;
}

Mesh* obj2D::CreateLetterL(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    glm::vec3 color)
{
    glm::vec3 startPoint = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(startPoint, color),
        VertexFormat(startPoint + glm::vec3(0, -200, 0), color),
        VertexFormat(startPoint + glm::vec3(100, -200, 0), color)
    };

    Mesh* letterL = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    letterL->SetDrawMode(GL_LINE_STRIP);

    letterL->InitFromData(vertices, indices);
    return letterL;
}

Mesh* obj2D::CreateLetterS(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    glm::vec3 color)
{
    glm::vec3 startPoint = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(startPoint, color),
        VertexFormat(startPoint + glm::vec3(-100, 0, 0), color),
        VertexFormat(startPoint + glm::vec3(-100, -100, 0), color),
        VertexFormat(startPoint + glm::vec3(0, -100, 0), color),
        VertexFormat(startPoint + glm::vec3(0, -200, 0), color),
        VertexFormat(startPoint + glm::vec3(-100, -200, 0), color)
    };

    Mesh* letterS = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3, 4, 5 };

    letterS->SetDrawMode(GL_LINE_STRIP);

    letterS->InitFromData(vertices, indices);
    return letterS;
}

Mesh* obj2D::CreateLetterE(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    glm::vec3 color)
{
    glm::vec3 startPoint = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(startPoint, color),
        VertexFormat(startPoint + glm::vec3(-100, 0, 0), color),
        VertexFormat(startPoint + glm::vec3(-100, -100, 0), color),
        VertexFormat(startPoint + glm::vec3(0, -100, 0), color),
        VertexFormat(startPoint + glm::vec3(-100, -100, 0), color),
        VertexFormat(startPoint + glm::vec3(-100, -200, 0), color),
        VertexFormat(startPoint + glm::vec3(0, -200, 0), color)
    };

    Mesh* letterE = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3, 4, 5, 6 };

    letterE->SetDrawMode(GL_LINE_STRIP);

    letterE->InitFromData(vertices, indices);
    return letterE;
}

Mesh* obj2D::CreateLetterW(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    glm::vec3 color)
{
    glm::vec3 startPoint = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(startPoint, color),
        VertexFormat(startPoint + glm::vec3(50, -200, 0), color),
        VertexFormat(startPoint + glm::vec3(100, 0, 0), color),
        VertexFormat(startPoint + glm::vec3(150, -200, 0), color),
        VertexFormat(startPoint + glm::vec3(200, 0, 0), color)
    };

    Mesh* letterW = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3, 4 };

    letterW->SetDrawMode(GL_LINE_STRIP);

    letterW->InitFromData(vertices, indices);
    return letterW;
}

Mesh* obj2D::CreateLetterI(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    glm::vec3 color)
{
    glm::vec3 startPoint = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(startPoint, color),
        VertexFormat(startPoint + glm::vec3(0, -200, 0), color)
    };

    Mesh* letterI = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1 };

    letterI->SetDrawMode(GL_LINE_STRIP);

    letterI->InitFromData(vertices, indices);
    return letterI;
}

Mesh* obj2D::CreateLetterN(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    glm::vec3 color)
{
    glm::vec3 startPoint = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(startPoint, color),
        VertexFormat(startPoint + glm::vec3(0, 200, 0), color),
        VertexFormat(startPoint + glm::vec3(100, 0, 0), color),
        VertexFormat(startPoint + glm::vec3(100, 200, 0), color)
    };

    Mesh* letterN = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    letterN->SetDrawMode(GL_LINE_STRIP);

    letterN->InitFromData(vertices, indices);
    return letterN;
}