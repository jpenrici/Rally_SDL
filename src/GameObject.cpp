#include "GameObject.h"
#include "TextureManager.h"

#include <string>
using std::string;

void GameObject::load(int x, int y, int width, int height, int frame, int row,
        string textureID)
{
    position = Vector2D(x, y);
    this->textureID = textureID;

    currentFrame = frame;
    currentRow = row;

    this->width = width;
    this->height = height;

    X = position.getX();
    Y = position.getY();
}

void GameObject::draw(SDL_Renderer* renderer)
{
    RallyTextureManager::Instance()->drawFrame(textureID, (int)position.getX(),
        (int)position.getY(), width, height, currentRow, currentFrame,
        renderer);
}

void GameObject::move(float x, float y)
{
    X = position.getX() + x;
    Y = position.getY() + y;
    position.setX(X);
    position.setY(Y);
}
