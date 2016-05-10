#include"game.h"
#include"SDL_image.h"

bool game::LoadContent()
{
    /** Texture loading - Begin **/

    std::string resourcesPaths = "resources\\textures.bmp";
    SDL_Surface *bmp = SDL_LoadBMP(resourcesPaths.c_str());

    SDL_SetColorKey(bmp, SDL_TRUE, SDL_MapRGB(bmp->format, 0, 0xC0, 0xC0) );

    if (bmp == nullptr)
    {
        std::cout << "Failed to load: " << resourcesPaths.c_str() << std::endl;
        return false;
    }

    texture = SDL_CreateTextureFromSurface(renderer, bmp);
    SDL_FreeSurface(bmp);
    if (texture == nullptr){
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return false;
    }

    /** Texture loading - End **/
    unsigned int tile_size = 100;
    level = new Map("resources\\levels\\level1.txt",texture, tile_size);
    //bomberman = new Player(textures[3], tile_size);

    return true;
}

