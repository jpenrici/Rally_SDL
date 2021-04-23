#include "Odometer.h"
#include "Utils.h"

#include <string>
using std::string;

Odometer::Odometer()
{
    currentMeter = ODOMETER_MIN;
    
    GameObject::load(57, 92, ODOMETER_WIDTH, ODOMETER_HEIGHT, 0, 1, "ometer");
}

void Odometer::draw(SDL_Renderer* renderer)
{
    GameObject::draw(renderer);
}

void Odometer::update()
{
    if (currentMeter <= ODOMETER_MIN)
    {
        currentMeter = ODOMETER_MIN;
    }

    if (currentMeter > ODOMETER_MAX)
    {
        currentMeter = ODOMETER_MAX;
    }

    currentFrame = int(currentMeter) % (ODOMETER_FRAMES);
    currentRow = int(currentMeter / ODOMETER_FRAMES) + 1;
}

void Odometer::value(int value)
{
    currentMeter = value;
}
