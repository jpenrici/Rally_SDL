#include "Speedometer.h"
#include "Utils.h"

#include <string>
using std::string;

Speedometer::Speedometer()
{
    currentVelocity = SPEEDOMETER_MIN;
    
    GameObject::load(10, 10, SPEEDOMETER_WIDTH, SPEEDOMETER_HEIGHT, 0, 1,
        "speedometer");
}

void Speedometer::draw(SDL_Renderer* renderer)
{
    GameObject::draw(renderer);
}

void Speedometer::update()
{
    if (currentVelocity <= SPEEDOMETER_MIN)
    {
        currentVelocity = SPEEDOMETER_MIN;
    }

    if (currentVelocity > SPEEDOMETER_MAX)
    {
        currentVelocity = SPEEDOMETER_MAX;
    }

    currentFrame = int(currentVelocity) % (SPEEDOMETER_FRAMES);
    currentRow = int(currentVelocity / SPEEDOMETER_FRAMES) + 1;
}

void Speedometer::velocity(float velocity)
{
    currentVelocity = velocity;
}
