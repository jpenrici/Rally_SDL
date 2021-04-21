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
    if (!RallyTextureManager::Instance()->load(PLAYER_PATH, "player", renderer))
    {
        cout << "load image fail\n";
        return false;
    }

    if (!RallyTextureManager::Instance()->load(SPEEDOMETER_PATH, "speedometer",
        renderer))
    {
        cout << "load image fail\n";
        return false;
    }

    if (!RallyTextureManager::Instance()->load(OBSTACLE_PATH, "obstacle",
        renderer))
    {
        cout << "load image fail\n";
        return false;
    }   

    cout << "init success\n";
    isRunning = true;

    return true;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);   
    
    player.draw(renderer);
    obstacle.draw(renderer);
    speedMeter.draw(renderer);

    SDL_RenderPresent(renderer);
}

void Game::update()
{
    player.update();
    obstacle.update();
    speedMeter.update();
                    
    obstacle.velocity(player.velocity());               
    speedMeter.velocity(player.velocity());

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

    bool stop = false;
    for (int x = player.X; x < player.X + PLAYER_WIDTH; x += 2)
    {
        stop = obstacle.checkCollision(x, player.Y);
        if (stop) 
        {
            printf("Collision ...");
            player.accelarate(-2);
            break;
        }
    }
    printf("\n");
}