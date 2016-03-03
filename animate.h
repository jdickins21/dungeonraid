//
//  animate.h
//  Dungeon Raid
//
//  Created by Jacob Dickinson on 2/15/15.
//  Copyright (c) 2015 Jacob Dickinson. All rights reserved.
//

#ifndef __Dungeon_Raid__animate__
#define __Dungeon_Raid__animate__

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>
#include <ctime>

class Animate{
public:
    void moveRightX(SDL_Rect rect, int speed);
    
    void moveLeftX(SDL_Rect rect, int speed);
    
    void moveUpY(SDL_Rect rect, int speed);
    
    void moveDownY(SDL_Rect rect, int speed);
    
    enum {
        UP,
        RIGHT,
        DOWN,
        LEFT,
        
        FACE_MAX
    };
    
    int speed = 3;
    
    
};

#endif /* defined(__Dungeon_Raid__animate__) */
