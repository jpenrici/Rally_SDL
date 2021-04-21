#ifndef __TextureManager_H__
#define __TextureManager_H__

#include <SDL2/SDL.h>

#include <string>
using std::string;

#include <map>
using std::map;

class TextureManager
{
public:

    bool load(string fileName, string id, SDL_Renderer* renderer);
    void draw(string id, int x, int y, int width, int height,
        SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(string id, int x, int y, int width, int height,
        int currentRow, int currentFrame, SDL_Renderer* renderer,
        SDL_RendererFlip flip = SDL_FLIP_NONE);
    void clearFromTextureMap(string id);

    static TextureManager* Instance()
    {
        if(instance == 0)
        {
            instance = new TextureManager();
            return instance;
        }
        return instance;
    }

private:

    TextureManager() {}

    map<string, SDL_Texture*> textureMap;
    static TextureManager* instance;
    
};

typedef TextureManager RallyTextureManager;

#endif // __TextureManager_H__
