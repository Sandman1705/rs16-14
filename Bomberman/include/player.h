#ifndef PLAYER_H
#define PLAYER_H

/**
 *  \file Player.h
 *
 *  Defines class Player which represents a player.
 *
 */

#include <SDL.h>
#include "Map.h"
#include "BombManager.h"
#include "KeyboardInput.h"

/** \class Player
 *  \brief class which represents a player
 *  \details This class contains all properties of a player like he's
 *           coordinates on a map, he's size, direction where he's going,
 *           he's speed as well as some information about bombs.
 *           Also contains a method Draw() which draws him on a proper place on
 *           map, method player_move() for moving around the map, update()
 *           for refreshing he's position and place_bomb() for
 *           placing bombs on map.
 */

class Player
{
    public:
        /**
         *  \brief Constructor for Player.
         *
         *  Makes an object of class Player according to given attributes.
         *  \param tex pointer to SDL_texture object from which the texture
         *         will be taken for method Draw()
         *  \param tile_size size of one tile on map
         *  \param bomb_manager list of bombs with methods for management
         *  \param keyboard_input pointer to KeyboardInput object of the game
         *         (which is used to keep track of input given by the user)
         *  \param level pointer to Map object of the game
         *  \param val_x coordinate of the player on the map
         *  \param val_y coordinate of the player on the map
         *
         */
        Player(SDL_Texture* tex, unsigned int tile_size, BombManager *bomb_manager,
               KeyboardInput *keyboard_input, Map *level,  unsigned int val_x = 0, unsigned int val_y = 0);

        unsigned int Get_x() const;
        void Set_x(unsigned int val);
        unsigned int Get_y() const;
        void Set_y(unsigned int val);

        unsigned int Get_size_w() const;
        unsigned int Get_size_h() const;

        unsigned int Get_status() const;
        void Set_status(int s);

        unsigned int Get_direction() const;
        void Set_direction(int d);

        /**
         *  \brief Function that implements movement for player.
         *
         *  Updates the position of player on the map according to it's
         *  parameters that depend on keys that player used.
         *  \param x value that represents where player wishes to go
         *  relative to he's current position on x axis
         *  \param y value that represents where player wishes to go
         *  relative to he's current position on y axis
         *  \param level pointer to Map object of the game
         *
         *  \return void
         */
        void player_move(int x, int y, Map *level);

        /**
         *  \brief Draws the player on given SDL_Renderer.
         *
         *  Draws the player on the map according to he's coordinates.
         *  \param renderer represents SDL_Renderer on which the player
         *  will be drawn on
         *
         *  \return void
         */
        void Draw(SDL_Renderer* renderer);

        /**
         *  \brief Places the bomb on the map.
         *
         *  Places the bomb on map on player's current position.
         *
         *  \return void
         */
        void place_bomb();

        /**
         *  \brief Updates player's position on map.
         *
         *  Updates player's position and calls appropriate actions according
         *  to KeyboardInput of user.
         *
         *  \return void
         */
        void update();

    protected:

    private:
        enum Direction
        {
              LEFT = 0,
              RIGHT = 1,
              UP = 2,
              DOWN = 3
        };
        Direction m_direction;
        bool m_bomb_ready = false;
        int m_status;
        unsigned int m_x;
        unsigned int m_y;
        unsigned int m_move_speed = 4;
        unsigned int m_player_size_w = 17;
        unsigned int m_player_size_h = 23;
        SDL_Texture* m_tex;
        unsigned int m_tile_size;
        BombManager* m_bomb_manager;
        KeyboardInput* m_keyboard_input;
        Map* m_level;
};

#endif // PLAYER_H
