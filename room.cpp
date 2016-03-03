//
//  room.cpp
//  Dungeon Raid
//
//  Created by Jacob Dickinson on 3/2/15.
//  Copyright (c) 2015 Jacob Dickinson. All rights reserved.
//

#include "room.h"



Room::Room(){
}

Room::~Room(){
}

void Room::moveLeft(int n){
    for(int i = 0; i < size; i++){
        boxes[i].x += n;
    }
    for(int i = 0; i < monsterSize; i++){
        monsters[i].monLoc.x += n;
    }
}


void Room::moveRight(int n){
    for(int i = 0; i < size; i++){
        boxes[i].x -= n;
    }
    for(int i = 0; i < monsterSize; i++){
        monsters[i].monLoc.x -= n;
    }
    
}
void Room::moveUp(int n){
    for(int i = 0; i < size; i++){
        boxes[i].y += n;
    }
    for(int i = 0; i < monsterSize; i++){
        monsters[i].monLoc.y += n;
    }
    
}
void Room::moveDown(int n){
    for(int i = 0; i < size; i++){
        boxes[i].y -= n;
    }
    for(int i = 0; i < monsterSize; i++){
        monsters[i].monLoc.y -= n;
    }
    
}

bool Room::detectCollision(SDL_Rect player){
    
    for(std::vector<SDL_Rect>::iterator it = hitBox.begin(); it != hitBox.end(); ++it){
        if(it->x < player.x + player.w &&
           it->x + it->w > player.x &&
           it->y < player.y + player.h &&
           it->h + it->y > player.y){
            return true;
        }
    }
    for(int i = 0; i < size; i++){
        if(boxes[i].x < player.x + player.w &&
           boxes[i].x + boxes[i].w > player.x &&
           boxes[i].y < player.y + player.h &&
           boxes[i].h + boxes[i].y > player.y){
            return true;
        }
    }
    
    return false;
}


void Room::detectAtk(SDL_Rect player, int dmg){
    for(int i = 0; i < monsterSize; i++){
        if(monsters[i].hBox.x < player.x + player.w &&
           monsters[i].hBox.x + monsters[i].hBox.w > player.x &&
           monsters[i].hBox.y < player.y + player.h &&
           monsters[i].hBox.h + monsters[i].hBox.y > player.y){
            monsters[i].takeDamage(dmg);
//            if(monsters[i].hp == 0){
//                for(int j = i; j < monsterSize; j++){
//                    monsters[j] = monsters[j+1];
//                }
//                monsterSize -= 1;
//            }
        }
    }
}