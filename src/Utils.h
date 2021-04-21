#ifndef __Utils_H__
#define __Utils_H__

// Window
#define SCREEN_TITLE "Game"
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

// Player
#define PLAYER_PATH            "../images/player-animate-alpha.png"
#define PLAYER_WIDTH           128
#define PLAYER_HEIGHT          256
#define PLAYER_FRAMES            6
#define PLAYER_ROWS              1
#define PLAYER_MOVE_HORIZONTAL   5
#define PLAYER_MOVE_VERTICAL     0

// Obstacle
#define OBSTACLE_PATH          "../images/obstacle-animate-alpha.png"
#define OBSTACLE_WIDTH         192
#define OBSTACLE_HEIGHT        192
#define OBSTACLE_FRAMES          6
#define OBSTACLE_ROWS            1
#define OBSTACLE_MIN             2
#define OBSTACLE_MAX            60

// Speedometer
#define SPEEDOMETER_PATH       "../images/speedometer-animate-alpha.png"
#define SPEEDOMETER_WIDTH      128
#define SPEEDOMETER_HEIGHT     128
#define SPEEDOMETER_FRAMES      10
#define SPEEDOMETER_ROWS         7
#define SPEEDOMETER_MIN          0
#define SPEEDOMETER_MAX         60

// FPS
#define FPS 60
#define DELAY_TIME 1000.0f/FPS

#endif // __Utils_H__