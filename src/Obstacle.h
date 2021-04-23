#ifndef __Obstacle_H__
#define __Obstacle_H__

#include "GameObject.h"
#include "Utils.h"

#include <string>
using std::string;

class Obstacle : public GameObject
{
public:

    Obstacle();
    ~Obstacle() {}
    
    void draw(SDL_Renderer* renderer);
    void update();

    int counter();
    void velocity(float velocity);
    bool checkCollision(float point_X, float point_Y);

private:
    const float VELOCITY_MIN = SPEEDOMETER_MIN;
    const float VELOCITY_MAX = SPEEDOMETER_MAX;
    
    int currentCounter;
    float currentVelocity;

    int rand_frame();
};

#endif // __Obstacle_H__
