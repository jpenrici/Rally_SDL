#include "Obstacle.h"
#include "Utils.h"

#include <iostream>

#include <cstdlib>
#include <string>
using std::string;

Obstacle::Obstacle()
{
    currentCounter = 0;
    currentVelocity = VELOCITY_MIN;
   
    GameObject::load(OBSTACLE_WIDTH, 0, OBSTACLE_WIDTH, OBSTACLE_HEIGHT,
        rand_frame(), 1, "obstacle");
}

void Obstacle::draw(SDL_Renderer* renderer)
{
    GameObject::draw(renderer);
}

void Obstacle::update()
{
    if (currentVelocity <= VELOCITY_MIN)
    {
        currentVelocity = VELOCITY_MIN;
    }

    if (currentVelocity > VELOCITY_MAX)
    {
        currentVelocity = VELOCITY_MAX;
    }

    if (position.getY() < SCREEN_HEIGHT - (OBSTACLE_HEIGHT * 0.1))
    {
        GameObject::move(0, currentVelocity * 0.1);
        return;
    }

    int interval = BORDER_RIGHT - BORDER_LEFT;
    int x = rand() % interval;
    position = Vector2D(BORDER_LEFT + x, 0);
    currentFrame = rand_frame();
    currentCounter++;
}

int Obstacle::rand_frame()
{
    return rand() % OBSTACLE_FRAMES;
}

int Obstacle::counter()
{
    return currentCounter;
}

void Obstacle::velocity(float velocity)
{
    currentVelocity = velocity;
}

bool Obstacle::checkCollision(float point_X, float point_Y)
{
    // Default
    float w = OBSTACLE_WIDTH;
    float h = OBSTACLE_HEIGHT;
    float x = position.getX();
    float y = position.getY();

    if (currentFrame < 4)
    {
        // Tree
        w = OBSTACLE_WIDTH  / 3;
        h = OBSTACLE_HEIGHT / 3;
        x = position.getX() + w;
        y = position.getY() + h;
    }

    Rectangle box(Vector2D(x, y), w, h);
    bool collision = box.contains(Vector2D(point_X, point_Y));

    if (collision)
    {
        position.setY(position.getY() - OBSTACLE_HEIGHT * 0.1);
    }

    return collision;
}
