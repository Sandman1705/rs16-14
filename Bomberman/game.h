#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include"includes.h"
#include"Map.h"
#include"Player.h"
#include"Enemy.h"
#include"Bomb.h"
#include"BombManager.h"

class game
{
private:
    bool Running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event Event;
    Map* level;
    Player *bomberman;
    Enemy *enemy;
    BombManager *bomb_manager;
    SDL_Texture* texture;

protected:

public:
    game();
    //virtual ~game();
    int OnExecute();
    bool OnInit();
    bool LoadContent();
    void OnEvent(SDL_Event* Event);
    void OnLoop();
    void OnRender();
    void Cleanup();

};
#endif // GAME_H_INCLUDED
