#pragma once

#include "components/simple_scene.h"

namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
     public:
        Tema1();
        ~Tema1();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

     protected:
         glm::ivec2 resolution;
         float translateX, translateY;
         float angularStep;
         glm::vec2 centerHead, centerLW, centerRW, centerDuck;
         float dx, dy, da;
         float duckAngle;
         float clock;
         glm::mat3 model;
         bool isDead;
         bool isFree;
         float speed;
         int lives;
         int bullets;
         int score;
         int respawns;

    };
}   // namespace m1
