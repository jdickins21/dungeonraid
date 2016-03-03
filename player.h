//
//  player.h
//  Dungeon Raid
//
//  Created by Jacob Dickinson on 2/15/15.
//  Copyright (c) 2015 Jacob Dickinson. All rights reserved.
//

#ifndef __Dungeon_Raid__player__
#define __Dungeon_Raid__player__

#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>
#include <SDL2/SDL_image.h>
#include <fstream>
#include "animate.h"
#include "room.h"

class Player : public Animate{
public:
    Player(SDL_Window* window, SDL_Renderer* renderer);
    
    ~Player();
    
    void setCurrRoom(Room room);
    
    void moveRightX(SDL_Rect rect, int speed);
    
    void moveLeftX(SDL_Rect rect, int speed);
    
    void moveUpY(SDL_Rect rect, int speed);
    
    void moveDownY(SDL_Rect rect, int speed);
    
    void walk(std::string facing);
    
    void hit(std::string facing);
    
    std::string getFaceState();
    
    SDL_Renderer* playRend;
    void setCurrrect(int i);
    
    SDL_Texture* sprite;
    SDL_Rect atkBox;
    SDL_Rect hBox;
    SDL_Rect currRect;
    SDL_Rect playerLoc;
    SDL_Rect clips[FACE_MAX][4];
    
    int speed = 16;
    int dmg = 1;
    Room currRoom;
    
private:
    
    std::string faceState;
    
    SDL_Rect *recpoint;
    
    
    int PLAYER_FPS;
    int PLAYER_TICKS_PER_FRAME;
};

#endif /* defined(__Dungeon_Raid__player__) */
