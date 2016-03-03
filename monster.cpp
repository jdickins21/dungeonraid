//
//  monster.cpp
//  Dungeon Raid
//
//  Created by Jacob Dickinson on 2/15/15.
//  Copyright (c) 2015 Jacob Dickinson. All rights reserved.
//

#include "monster.h"

Monster::Monster(){
    
}

Monster::Monster(SDL_Renderer* renderer, int x, int y){
    
    xLoc = x;
    yLoc = y;
    
    //rect on screen
    monLoc.x = xLoc;
    monLoc.y = yLoc;
    monLoc.w = 64;
    monLoc.h = 64;
    
    //hit box
    hBox.x = xLoc + 10;
    hBox.y = yLoc + 9;
    hBox.h = 51;
    hBox.w = 48;
    
    // get the layer
    SDL_Surface* loadedSurface = IMG_Load("goblin.png");
    SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0xFF, 0, 0xFF ) );
    sprite = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    
    currRect.x = 0;
    currRect.y = 0;
    currRect.w = 64;
    currRect.h = 64;
}

Monster::~Monster(){
    
}

void Monster::move(std::string direction){
    if(direction == "left"){
        xLoc -= 16;
    }
    if(direction == "right"){
        xLoc += 16;
    }
    if(direction == "up"){
        yLoc -= 16;
    }
    if(direction == "down"){
        yLoc += 16;
    }
}


void Monster::takeDamage(int dmg){
    hp -= dmg;
}