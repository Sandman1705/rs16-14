#include"game.h"
#include"SDL_image.h"

bool game::LoadContent()
{
    /** Texture loading - Begin **/
    std::string resourcesPath = "resources\\textures.bmp";
    SDL_Surface *bmp = SDL_LoadBMP(resourcesPath.c_str());

    SDL_SetColorKey(bmp, SDL_TRUE, SDL_MapRGB(bmp->format, 0, 0xC0, 0xC0) );

    if (bmp == nullptr)
    {
        std::cout << "Failed to load: " << resourcesPath.c_str() << std::endl;
        return false;
    }

    texture = SDL_CreateTextureFromSurface(renderer, bmp);
    SDL_FreeSurface(bmp);
    if (texture == nullptr){
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return false;
    }
    /** Texture loading - End **/

    /** Game objects initializing - Begin **/
    unsigned int tile_size = 44;
    level = new Map("resources\\levels\\level2.txt",texture, tile_size);
    explosion_manager = new ExplosionManager(texture, tile_size);
    bomb_manager = new BombManager(texture, tile_size, explosion_manager, level);
    bomberman = new Player(texture, tile_size, bomb_manager);
    enemy = new Enemy(texture, tile_size);
    /** Game objects initializing - End **/

    return true;
}

