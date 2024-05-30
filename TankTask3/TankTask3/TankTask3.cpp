#include "SpriteObject.h"
#include "GameObject.h"
#include "raylib-cpp.hpp"
#include "TankPlayer.h"
//#include "Ray.h"
#include "Barrel.h"
#include "Barriers.h"

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
    raylib::Texture2D targetBarrel("res/barrelGreen_side.png");


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

    Barrel barrelObject(MathClasses::Vector3(1500, 300, 1));
    barrelObject.SetParent(&root);
    barrelObject.Sprite = &targetBarrel;
    //barrelObject.SetLocalPosition(1500, 300);

    //attempt at putting a collider on the barrel
    /*GameObject barrelCollider;
    barrelCollider.SetParent(&root);
    barrelCollider.SetLocalPosition(1500, 300);*/

    Player.mBulletSpawn(&testDotSprite);

    std::vector<Collider*> colliderVec;
    //raylib Y - top
    Barriers botBarrier(MathClasses::Vector3(0, -1, 0), 895);
    Barriers topBarrier(MathClasses::Vector3(0, 1, 0), -5);
    Barriers leftBarrier(MathClasses::Vector3(1, 0, 0), -5);
    Barriers rightBarrier(MathClasses::Vector3(-1, 0, 0), 1675);

    botBarrier.SetParent(&root);
    topBarrier.SetParent(&root);
    leftBarrier.SetParent(&root);
    rightBarrier.SetParent(&root);
    
    

    while (!window.ShouldClose())
    {
        float deltaTime = window.GetFrameTime();

        //Player.Update(deltaTime);
        root.Update(deltaTime);
        root.GetColliders(colliderVec);

        //Check every collide agaisnt every other collider
        /*
        for every collider i
            for every collider j 
                as long as i != j
                    check collision for i agaisnt j
        */

        for (int i = 0; i < colliderVec.size(); i++)
        {
            for (int j = 0; j < colliderVec.size(); j++)
            {
                if (i != j)
                {
                    colliderVec[i]->CollisionCheck(colliderVec[j]);
                }
            }
        }

        colliderVec.clear();

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
