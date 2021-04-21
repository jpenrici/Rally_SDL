#ifndef __GameObject_H__
#define __GameObject_H__

#include "Geometry.h"

#include <SDL2/SDL.h>

#include <string>
using std::string;

class GameObject
{
public:
    
    void load(int x, int y, int width, int height, int frame, int row,
        string textureID);  
    void draw(SDL_Renderer* renderer);
    void update() {}
    void clean() {}

    void move(float x, float y);

    // Public Access
    float X;
    float Y;

protected:
    Vector2D position;
    string textureID;

    int currentFrame;
    int currentRow;

    int width;
    int height;
};

#endif // __GameObject_H__