//
//  cave.h
//  Dungeon Raid
//
//  Created by Jacob Dickinson on 3/3/15.
//  Copyright (c) 2015 Jacob Dickinson. All rights reserved.
//

#ifndef __Dungeon_Raid__cave__
#define __Dungeon_Raid__cave__

#include <stdio.h>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "room.h"
#include "monster.h"

class Cave{
public:
    Room roomOne;
    Room roomTwo;
    Room roomThree;
    Room roomFour;
    Room roomFive;
    Room roomSix;
    Room currMap;
    
    Cave(SDL_Window* window, SDL_Renderer* mapRend);
    
    ~Cave();
    
    void changeRoom(Room room1, int x = NULL, int y = NULL, int* playerX = NULL, int* playerY = NULL, int* playhX = NULL, int* plahY = NULL, int* playatx = NULL, int* playaty = NULL);
};

#endif /* defined(__Dungeon_Raid__cave__) */
