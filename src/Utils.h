#ifndef __Utils_H__
#define __Utils_H__

// Window
#define SCREEN_TITLE "Game"
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600
#define BORDER_LEFT   100
#define BORDER_RIGHT  550

// Background
#define BG_PATH				   "../images/background.png"
#define BG_WIDTH               800
#define BG_HEIGHT              600

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

// Ometer
#define ODOMETER_PATH          "../images/odometer-animate-alpha.png"
#define ODOMETER_WIDTH          34
#define ODOMETER_HEIGHT         20
#define ODOMETER_FRAMES         10
#define ODOMETER_ROWS           50
#define ODOMETER_MIN             0
#define ODOMETER_MAX           500

// FPS
#define FPS 60
#define DELAY_TIME 1000.0f/FPS

#endif // __Utils_H__