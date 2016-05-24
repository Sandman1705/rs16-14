#include "Entity/EnemyTwo.h"
#include "Manager/Map.h"
#include "Constants/TextureEnemyConstants.h"

EnemyTwo::EnemyTwo(SDL_Texture* tex, unsigned int tile_size, unsigned int val_x, unsigned int val_y)
 : Enemy(tex, tile_size, val_x, val_y)
{
    m_speed = 74; //timer speed
    m_move_speed = m_move_speed *m_tile_size/32; //speed according to 32px tile size

    m_rotation_const = 3;
    m_enemy_size_w = TEXTURE_ENEMY_TWO_SIZE_W *tile_size/32;
    m_enemy_size_h = TEXTURE_ENEMY_TWO_SIZE_H *tile_size/32; //size according to 32px tile size
}

void EnemyTwo::Draw(SDL_Renderer *renderer)
{
    SDL_Rect SrcR;
    SDL_Rect DestR;

    SrcR.y = TEXTURE_ENEMY_TWO_Y;
    SrcR.w = TEXTURE_ENEMY_TWO_SOURCE_W;
    SrcR.h = TEXTURE_ENEMY_TWO_SOURCE_H;

    if(m_status % m_rotation_const == 0)
    {
        SrcR.x = TEXTURE_ENEMY_TWO_X;
    }
    if(m_status % m_rotation_const == 1)
    {
        SrcR.x = TEXTURE_ENEMY_TWO_X + TEXTURE_ENEMY_TWO_TEXTURE_OFFSET;
    }
    if(m_status % m_rotation_const == 2)
    {
        SrcR.x = TEXTURE_ENEMY_TWO_X + 2*TEXTURE_ENEMY_TWO_TEXTURE_OFFSET;
    }

    DestR.x = m_x;
    DestR.y = m_y;
    DestR.w = m_enemy_size_w;
    DestR.h = m_enemy_size_h;

    SDL_RenderCopy(renderer, m_tex, &SrcR, &DestR);
}
