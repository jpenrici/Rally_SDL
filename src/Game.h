#ifndef __Game_H__
#define __Game_H__

#include "TextureManager.h"
#include "Speedometer.h"
#include "Obstacle.h"
#include "Player.h"
#include "Utils.h"

#include <SDL2/SDL.h>

class Game
{
public:

    ~Game() {}

    bool init();
    void handleEvents();
    void update();  
    void render();
    void clean();
    void quit();
    void status();
    bool running();

    SDL_Renderer* getRenderer() const;

    static Game* Instance()
    {
        if(instance == 0)
        {
            instance = new Game();
            return instance;
        }
        
        return instance;
    }

private:

    Game() {}

    SDL_Window* window;
    SDL_Renderer* renderer;

    Player player;
    Obstacle obstacle;
    Speedometer speedMeter;

    bool isRunning;

    static Game* instance;
};

typedef Game RallyGame;

#endif // __Game_H__
