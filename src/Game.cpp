#include "Game.h"

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

Game* Game::instance = 0;

bool Game::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "SDL init fail\n";
        return false;
    }
        
    window = SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == 0)
    {
        cout << "window init fail\n";
        return false;
    }           

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == 0)
    {
        cout << "renderer init fail\n";
        return false;       
    }

    // load textures
    vector<vector<string> > data {
        {PLAYER_PATH,           "player"},
        {OBSTACLE_PATH,       "obstacle"},
        {ODOMETER_PATH,       "odometer"},
        {SPEEDOMETER_PATH, "speedometer"},
        {BG_PATH,            "landscape"}
    };
    for (auto i : data)
    {
        if (!RallyTextureManager::Instance()->load(i[0], i[1], renderer))
        {
            cout << "load image fail\n";
            return false;
        }
    }

    // Background
    landscape.load(0, 0, BG_WIDTH, BG_HEIGHT, 0, 1, "landscape");

    cout << "init success\n";
    isRunning = true;

    return true;
}

void Game::render()
{
    SDL_RenderClear(renderer);

    landscape.draw(renderer);
    player.draw(renderer);
    obstacle.draw(renderer);
    speedometer.draw(renderer);
    odometer.draw(renderer);

    SDL_RenderPresent(renderer);
}

void Game::update()
{
    landscape.draw(renderer);
    player.update();
    obstacle.update();
    speedometer.update();
    odometer.update();
                     
    status();   
}

void Game::handleEvents()
{
    SDL_Event event;

    if(SDL_PollEvent(&event) != 0)
    {
        if(event.type == SDL_QUIT)
        {
            isRunning = false;
        }
        else if(event.type == SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_UP:
                    player.accelarate(+1);
                    break;
                case SDLK_DOWN:
                    player.accelarate(-1);
                    break;
                case SDLK_LEFT:
                    player.moveLeft();
                    break;
                case SDLK_RIGHT:
                    player.moveRight();
                    break;
                default:
                    break;  
            }   
        }
    }
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::quit()
{
    isRunning = false;
}

bool Game::running()
{
    return isRunning;
}

SDL_Renderer* Game::getRenderer() const
{
    return renderer;
}

void Game::status()
{
    printf("Player  : Position (%.2f, %.2f) Velocity: %.2f\n", player.X,
        player.Y, player.velocity());
    printf("Obstacle: Position (%.2f, %.2f) ", obstacle.X, obstacle.Y);

    // Update dynamics
    obstacle.velocity(player.velocity());               
    speedometer.velocity(player.velocity());
    odometer.value(obstacle.counter());

    // Out of range
    if (player.X < BORDER_LEFT || player.X > BORDER_RIGHT)
    {
        if (player.velocity() > 5)
        {
            printf("Alert !!!");
            player.accelarate(-1);
        }
    }

    // Check collisions
    for (int x = player.X; x < player.X + PLAYER_WIDTH; x += 2)
    {
        if (obstacle.checkCollision(x, player.Y)) 
        {
            printf("Collision ...");
            player.accelarate(-1);
            break;
        }
    }
    printf("\n");
}