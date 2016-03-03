//
//  monster.h
//  Dungeon Raid
//
//  Created by Jacob Dickinson on 2/15/15.
//  Copyright (c) 2015 Jacob Dickinson. All rights reserved.
//

#ifndef __Dungeon_Raid__monster__
#define __Dungeon_Raid__monster__

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "animate.h"

class Monster : public Animate{
public:
    int xLoc;
    int yLoc;
    int hp = 3;
    
    SDL_Texture* sprite;
    
    SDL_Rect hBox;
    
    SDL_Rect currRect;
    
    SDL_Rect monLoc;
    
    Monster(SDL_Renderer* renderer, int x, int y);
    Monster();
    ~Monster();
    void move(std::string direction);
    void takeDamage(int dmg);
    
};

#endif /* defined(__Dungeon_Raid__monster__) */
