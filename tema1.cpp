#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/tr2D.h"
#include "lab_m1/Tema1/obj2D.h"

using namespace std;
using namespace m1;

/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}

void Tema1::Init()
{
    resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);
    translateX = rand() % 1281;                 //Random float in [0, 1280]
    translateY = 0;
    angularStep = 0;
    centerHead = glm::vec2(0, 0);
    centerLW = glm::vec2(-15, -80);
    centerRW = glm::vec2(15, -80);
    centerDuck = glm::vec2(0, -75);
    dx = (rand() % 2001 * 1.0 - 1000) / 1000;   //Random float in [-1, 1]
    dy = (500 + rand() % 501 * 1.0) / 1000;     //Random float in [0.5, 1]
    da = 1;
    clock = 0;
    isDead = false;
    isFree = false;
    speed = 180;
    score = 0;
    respawns = 0;
    lives = 3;
    bullets = 4;

    //Create objects
    Mesh* head = obj2D::CreateHead("head", glm::vec3(0, 0, 0), 30, glm::vec3(0.282f, 0.294f, 0.858f));
    meshes["head"] = head;
    Mesh* body = obj2D::CreateBody("body", glm::vec3(0, 0, 0), glm::vec3(0.282f, 0.294f, 0.858f));
    meshes["body"] = body;
    Mesh* leftWing = obj2D::CreateLeftWing("leftWing", glm::vec3(-15, -80, 0), glm::vec3(0.282f, 0.294f, 0.858f));
    meshes["leftWing"] = leftWing;
    Mesh* rightWing = obj2D::CreateRightWing("rightWing", glm::vec3(15, -80, 0), glm::vec3(0.282f, 0.294f, 0.858f));
    meshes["rightWing"] = rightWing;
    Mesh* beak = obj2D::CreateBeak("beak", glm::vec3(-5, 25, 0), glm::vec3(0.988f, 0.729f, 0.011f));
    meshes["beak"] = beak;
    Mesh* eye = obj2D::CreateHead("eye", glm::vec3(-15, 10, 1), 5, glm::vec3(0, 0, 0));
    meshes["eye"] = eye;
    Mesh* life1 = obj2D::CreateHead("life1", glm::vec3(0, 0, 0), 15, glm::vec3(1, 0, 0));
    meshes["life1"] = life1;
    Mesh* life2 = obj2D::CreateHead("life2", glm::vec3(30, 0, 0), 15, glm::vec3(1, 0, 0));
    meshes["life2"] = life2;
    Mesh* life3 = obj2D::CreateHead("life3", glm::vec3(60, 0, 0), 15, glm::vec3(1, 0, 0));
    meshes["life3"] = life3;
    Mesh* bullet1 = obj2D::CreateBullet("bullet1", glm::vec3(0, 0, 0), glm::vec3(0.129f, 0.458f, 0.035f));
    meshes["bullet1"] = bullet1;
    Mesh* bullet2 = obj2D::CreateBullet("bullet2", glm::vec3(20, 0, 0), glm::vec3(0.129f, 0.458f, 0.035f));
    meshes["bullet2"] = bullet2;
    Mesh* bullet3 = obj2D::CreateBullet("bullet3", glm::vec3(40, 0, 0), glm::vec3(0.129f, 0.458f, 0.035f));
    meshes["bullet3"] = bullet3;
    Mesh* bullet4 = obj2D::CreateBullet("bullet4", glm::vec3(60, 0, 0), glm::vec3(0.129f, 0.458f, 0.035f));
    meshes["bullet4"] = bullet4;
    Mesh* scoreEdge = obj2D::CreateRectangle("scoreEdge", glm::vec3(0, 0, 0), glm::vec3(1, 0, 0), false, 200, 40);
    meshes["scoreEdge"] = scoreEdge;
    Mesh* scoreBar = obj2D::CreateRectangle("scoreBar", glm::vec3(0, 0, 0), glm::vec3(1, 0, 0), true, 20, 40);
    meshes["scoreBar"] = scoreBar;
    Mesh* grass = obj2D::CreateRectangle("grass", glm::vec3(0, 0, 2), glm::vec3(0.027f, 0.89f, 0.125f), true, 1280, 60);
    meshes["grass"] = grass;
    Mesh* letterL = obj2D::CreateLetterL("letterL", glm::vec3(0, 0, 0), glm::vec3(1, 0, 0));
    meshes["letterL"] = letterL;
    Mesh* letterO = obj2D::CreateRectangle("letterO", glm::vec3(0, 0, 0), glm::vec3(1, 0, 0), false, 100, 200);
    meshes["letterO"] = letterO;
    Mesh* letterS = obj2D::CreateLetterS("letterS", glm::vec3(0, 0, 0), glm::vec3(1, 0, 0));
    meshes["letterS"] = letterS;
    Mesh* letterE = obj2D::CreateLetterE("letterE", glm::vec3(0, 0, 0), glm::vec3(1, 0, 0));
    meshes["letterE"] = letterE;
    Mesh* letterW = obj2D::CreateLetterW("letterW", glm::vec3(0, 0, 0), glm::vec3(0, 0, 1));
    meshes["letterW"] = letterW;
    Mesh* letterI = obj2D::CreateLetterI("letterI", glm::vec3(0, 0, 0), glm::vec3(0, 0, 1));
    meshes["letterI"] = letterI;
    Mesh* letterN = obj2D::CreateLetterN("letterN", glm::vec3(0, 0, 0), glm::vec3(0, 0, 1));
    meshes["letterN"] = letterN;
}

void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.2f, 0.8f, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::Update(float deltaTimeSeconds)
{
    model = glm::mat3(1);
    auto lwModel = glm::mat3(1);
    auto rwModel = glm::mat3(1);

    //Set lives
    auto modelLives = glm::mat3(1);
    modelLives = tr2D::Translate(15, 700) * modelLives;

    //Set bullets
    auto modelBullets = glm::mat3(1);
    modelBullets = tr2D::Translate(10, 640) * modelBullets;

    //Set score
    auto modelScore = glm::mat3(1);
    modelScore = tr2D::Translate(resolution.x - 200, resolution.y - 40);

    //Calculate duck angle
    duckAngle = atan2(dy, dx) - M_PI_2;

    //Rotate duck 45 degrees
    model = tr2D::Translate(translateX, translateY) * tr2D::Rotate(duckAngle) * model;
    lwModel = tr2D::Translate(translateX, translateY) * tr2D::Rotate(duckAngle) * lwModel;
    rwModel = tr2D::Translate(translateX, translateY) * tr2D::Rotate(duckAngle) * rwModel;
    
    glm::vec2 newCenter = glm::vec2(model * glm::vec3(centerHead, 1));
    glm::vec2 newCenterLW = glm::vec2(lwModel * glm::vec3(centerLW, 1));
    glm::vec2 newCenterRW = glm::vec2(rwModel * glm::vec3(centerRW, 1));

    //Rotate wings
    angularStep += da * deltaTimeSeconds * 5;
    if (angularStep < -0.3f)
        da = 1;
    if (angularStep > 0.3f)
        da = -1;
    
    //Rotate wings
    lwModel = tr2D::Translate(newCenterLW.x, newCenterLW.y) * tr2D::Rotate(angularStep) * tr2D::Translate(-newCenterLW.x, -newCenterLW.y) * lwModel;
    rwModel = tr2D::Translate(newCenterRW.x, newCenterRW.y) * tr2D::Rotate(-angularStep) * tr2D::Translate(-newCenterRW.x, -newCenterRW.y) * rwModel;
    
    if (bullets == 0 && !isDead)
        isFree = true;

    clock += deltaTimeSeconds;
    if (clock < 7)
    {
        if (isDead)
        {
            dx = 0;
            dy = -1;
            clock = 0;
            if (newCenter.y < -100)
            {
                score++;

                //Increase speed after 3 respawns
                respawns++;
                if (respawns % 3 == 0)
                    speed += speed / 2;

                translateX = rand() % 1280;
                translateY = 0;
                dx = (rand() % 2001 * 1.0 - 1000) / 1000;   //Random float in [-1, 1]
                dy = (500 + rand() % 501 * 1.0) / 1000;    //Random float in [0.5, 1]
                isDead = false;

                bullets = 4;
            }
        }
        else
        {
            //Edge bounce
            if (newCenter.x > resolution.x)
                dx = -1;
            if (newCenter.y > resolution.y)
                dy = -1;
            if (newCenter.x < 0)
                dx = 1;
            if (newCenter.y < 0)
                dy = 1;
        }
    }
    else
        isFree = true;

    if (isFree)
    {
        dx = 0;
        dy = 1;
        if (newCenter.y > resolution.x + 20)
        {
            lives--;

            //Increase speed after 3 respawns
            respawns++;
            if (respawns % 3 == 0)
                speed += speed / 2;

            translateX = rand() % 1280;
            translateY = 0;
            dx = (rand() % 2001 * 1.0 - 1000) / 1000;   //Random float in [-1, 1]
            dy = (500 + rand() % 501 * 1.0) / 1000;    //Random float in [0.5, 1]
            isFree = false;
            clock = 0;

            bullets = 4;
        }
    }

    if(lives > 0 && score < 10)
    {
        //Render duck
        RenderMesh2D(meshes["head"], shaders["VertexColor"], model);
        RenderMesh2D(meshes["body"], shaders["VertexColor"], model);
        RenderMesh2D(meshes["leftWing"], shaders["VertexColor"], lwModel);
        RenderMesh2D(meshes["rightWing"], shaders["VertexColor"], rwModel);
        RenderMesh2D(meshes["beak"], shaders["VertexColor"], model);
        RenderMesh2D(meshes["eye"], shaders["VertexColor"], model);

        //Render lives
        switch (lives) 
        {
        case 1:
            RenderMesh2D(meshes["life1"], shaders["VertexColor"], modelLives);
            break;
        case 2:
            RenderMesh2D(meshes["life1"], shaders["VertexColor"], modelLives);
            RenderMesh2D(meshes["life2"], shaders["VertexColor"], modelLives);
            break;
        case 3:
            RenderMesh2D(meshes["life1"], shaders["VertexColor"], modelLives);
            RenderMesh2D(meshes["life2"], shaders["VertexColor"], modelLives);
            RenderMesh2D(meshes["life3"], shaders["VertexColor"], modelLives);
            break;
        }

        //Render bullets
        switch (bullets)
        {
        case 4:
            RenderMesh2D(meshes["bullet1"], shaders["VertexColor"], modelBullets);
            RenderMesh2D(meshes["bullet2"], shaders["VertexColor"], modelBullets);
            RenderMesh2D(meshes["bullet3"], shaders["VertexColor"], modelBullets);
            RenderMesh2D(meshes["bullet4"], shaders["VertexColor"], modelBullets);
            break;
        case 3:
            RenderMesh2D(meshes["bullet1"], shaders["VertexColor"], modelBullets);
            RenderMesh2D(meshes["bullet2"], shaders["VertexColor"], modelBullets);
            RenderMesh2D(meshes["bullet3"], shaders["VertexColor"], modelBullets);
            break;
        case 2:
            RenderMesh2D(meshes["bullet1"], shaders["VertexColor"], modelBullets);
            RenderMesh2D(meshes["bullet2"], shaders["VertexColor"], modelBullets);
            break;
        case 1:
            RenderMesh2D(meshes["bullet1"], shaders["VertexColor"], modelBullets);
            break;
        }

        //Render score
        RenderMesh2D(meshes["scoreEdge"], shaders["VertexColor"], modelScore);

        //Fill score
        for (int i = 0; i < score; i++)
            RenderMesh2D(meshes["scoreBar"], shaders["VertexColor"], tr2D::Translate(resolution.x - 200 + i * 20, resolution.y - 40));
    }
    
    //Render grass
    RenderMesh2D(meshes["grass"], shaders["VertexColor"], tr2D::Translate(0, 0));

    //Display LOSE
    if (lives == 0)
    {
        if(clock >= 0.5f)
        {
            RenderMesh2D(meshes["letterL"], shaders["VertexColor"], tr2D::Translate(300, 500));
            RenderMesh2D(meshes["letterO"], shaders["VertexColor"], tr2D::Translate(500, 300));
            RenderMesh2D(meshes["letterS"], shaders["VertexColor"], tr2D::Translate(800, 500));
            RenderMesh2D(meshes["letterE"], shaders["VertexColor"], tr2D::Translate(1000, 500));
        }
        if (clock >= 1)
            clock = 0;
    }

    //Display WIN
    if (score == 10)
    {
        if (clock >= 0.5f)
        {
            RenderMesh2D(meshes["letterW"], shaders["VertexColor"], tr2D::Translate(400, 500));
            RenderMesh2D(meshes["letterI"], shaders["VertexColor"], tr2D::Translate(700, 500));
            RenderMesh2D(meshes["letterN"], shaders["VertexColor"], tr2D::Translate(800, 300));
        }
        if (clock >= 1)
            clock = 0;
    }

    //Move duck
    translateX += dx * deltaTimeSeconds * speed;
    translateY += dy * deltaTimeSeconds * speed;
}


void Tema1::FrameEnd()
{
}

/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{
}


void Tema1::OnKeyRelease(int key, int mods)
{
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{   
    //Hit the duck as long as it is not dead nor free
    if (!isDead && !isFree)
    {
        bullets--;

        glm::vec2 newCenterDuck = glm::vec2(model * glm::vec3(centerDuck, 1));
        if (glm::distance(newCenterDuck, glm::vec2(mouseX, resolution.y - mouseY)) < 85)
            isDead = true;
    }
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}
