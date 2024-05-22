#include "SpriteObject.h"
#include "GameObject.h"
#include "raylib-cpp.hpp"
#include "TankPlayer.h"

#include <iostream>

int main()
{
    int screenWidth = 1680;
    int screenHeight = 900;
    raylib::Color textColor = raylib::Color::LightGray();
    raylib::Window window(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);


    raylib::Texture2D tankSprite("res/tankBody_blue_outline.png");
    raylib::Texture2D tankBarrel("res/tankBlue_barrel1_outline.png");
    raylib::Texture2D bulletSprite("res/bulletBlue1_outline.png");
    raylib::Texture2D testDot("res/barrelBlack_top.png");

    GameObject root;
    GameObject::setRoot(&root);

    TankPlayer Player;
    Player.SetParent(GameObject::getRoot());
    SpriteObject tankBarrelSprite;
    GameObject barrelPivot;
    Player.Sprite = &tankSprite;
    tankBarrelSprite.Sprite = &tankBarrel;
    Player.SetLocalPosition(screenWidth / 2, screenHeight / 2);

    barrelPivot.SetParent(&Player);
    tankBarrelSprite.SetParent(&barrelPivot);
    tankBarrelSprite.SetLocalPosition(30, 0);

    GameObject testDotSprite;
    testDotSprite.SetParent(&barrelPivot);
    //testDotSprite.Sprite = &testDot;
    testDotSprite.SetLocalPosition(65, 0);

    Player.mBulletSpawn(&testDotSprite);

    while (!window.ShouldClose())
    {
        float deltaTime = window.GetFrameTime();

        //Player.Update(deltaTime);
        root.Update(deltaTime);

        BeginDrawing();
        {
            window.ClearBackground(RAYWHITE);

            //Player.Draw();
            root.Draw();
        }
        EndDrawing();
    }

    return 0;
    
}
