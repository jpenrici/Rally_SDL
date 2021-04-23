#ifndef __Odometer_H__
#define __Odometer_H__

#include "GameObject.h"
#include "Utils.h"

#include <string>
using std::string;

class Odometer : public GameObject
{
public:

    Odometer();
    ~Odometer() {}
    
    void draw(SDL_Renderer* renderer);
    void update();

    void value(int value);

private:

    float currentMeter;
};

#endif // __Odometer_H__
