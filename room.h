//
//  room.h
//  Dungeon Raid
//
//  Created by Jacob Dickinson on 3/2/15.
//  Copyright (c) 2015 Jacob Dickinson. All rights reserved.
//

#ifndef __Dungeon_Raid__room__
#define __Dungeon_Raid__room__

#include <stdio.h>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <memory>
#include "monster.h"

class Room{
public:
    int ID;
    int height = NULL;
    int width = NULL;
    int size;
    int monsterSize;
    SDL_Texture* roomText;
    std::vector<SDL_Rect> hitBox;
    SDL_Rect* boxes;
    Monster* monsters;
    SDL_Rect roomRect;
    SDL_Rect roomOnRect;
    
    Room();
    ~Room();
    bool detectCollision(SDL_Rect player);
    void detectAtk(SDL_Rect player, int dmg);
    void moveLeft(int n);
    void moveRight(int n);
    void moveUp(int n);
    void moveDown(int n);
};

#endif /* defined(__Dungeon_Raid__room__) */
