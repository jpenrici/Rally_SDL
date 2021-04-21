#ifndef __Speedometer_H__
#define __Speedometer_H__

#include "GameObject.h"
#include "Utils.h"

#include <string>
using std::string;

class Speedometer : public GameObject
{
public:

    Speedometer();
    ~Speedometer() {}
    
    void draw(SDL_Renderer* renderer);
    void update();

    void velocity(float velocity);

private:

    float currentVelocity;
};

#endif // __Speedometer_H__
