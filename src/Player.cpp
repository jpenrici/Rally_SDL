#include "Player.h"
#include "Utils.h"

#include <string>
using std::string;

Player::Player()
{
    stop = false;
    currentVelocity = VELOCITY_MIN;

    int x = (SCREEN_WIDTH / 2) - (PLAYER_WIDTH / 2);
    int y = SCREEN_HEIGHT - PLAYER_HEIGHT;
    GameObject::load(x, y, PLAYER_WIDTH, PLAYER_HEIGHT, 0, 1, "player");
}

void Player::draw(SDL_Renderer* renderer)
{
    GameObject::draw(renderer);
}

void Player::update()
{
    if (currentVelocity <= VELOCITY_MIN)
    {
        currentFrame = 4;
        return;
    }

    if (stop)
    {
        currentFrame = 5;
        stop = false;
        return;
    }
    
    if (currentVelocity > VELOCITY_MIN)
    {
        currentFrame = int(((SDL_GetTicks() / 100) % 4));
    }
}

void Player::moveLeft()
{
    if (currentVelocity <= VELOCITY_MIN)
    {
        return;
    }

    if (position.getX() > (PLAYER_WIDTH * 0.1))
    {
        GameObject::move(-HORIZONTAL_OFFSET, VERTICAL_OFFSET);
    }
}

void Player::moveRight()
{
    if (currentVelocity <= VELOCITY_MIN)
    {
        return;
    }

    if (position.getX() < SCREEN_WIDTH - (PLAYER_WIDTH * 0.9))
    {
        GameObject::move(HORIZONTAL_OFFSET, VERTICAL_OFFSET);
    }
}

float Player::velocity()
{
    return currentVelocity;
}

void Player::accelarate(float value)
{
    currentVelocity += value;

    if (currentVelocity < VELOCITY_MIN)
    {
        currentVelocity = VELOCITY_MIN;
    }

    if (currentVelocity > VELOCITY_MAX)
    {
        currentVelocity = VELOCITY_MAX;
    }

    if (value < 0)
    {
        stop = true;
    }
}
