#ifndef __Player_H__
#define __Player_H__

#include "GameObject.h"
#include "Utils.h"

#include <string>
using std::string;

class Player : public GameObject
{
public:

    Player();
    ~Player() {}
    
    void draw(SDL_Renderer* renderer);
    void update();

    void moveLeft();
    void moveRight();

    float velocity();
    void accelarate(float value);

private:
    const int HORIZONTAL_OFFSET = PLAYER_MOVE_HORIZONTAL;
    const int VERTICAL_OFFSET = PLAYER_MOVE_VERTICAL;
    const float VELOCITY_MIN = SPEEDOMETER_MIN;
    const float VELOCITY_MAX = SPEEDOMETER_MAX;

    float currentVelocity;
    bool stop;
};

#endif // __Player_H__
