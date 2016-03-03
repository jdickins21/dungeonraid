//
//  player.cpp
//  Dungeon Raid
//
//  Created by Jacob Dickinson on 2/15/15.
//  Copyright (c) 2015 Jacob Dickinson. All rights reserved.
//

#include "player.h"

Player::Player(SDL_Window* window, SDL_Renderer* renderer){
    playRend = renderer;
    
    //rect on screen
    playerLoc.x = 250;
    playerLoc.y = 250;
    playerLoc.w = 64;
    playerLoc.h = 64;
    
    //hit box
    hBox.x = 270;
    hBox.y = 291;
    hBox.h = 27;
    hBox.w = 20;
    
    //attack box
    atkBox.x = 278;
    atkBox.y = 276;
    atkBox.w = 50;
    atkBox.h = 19;
    
    
    
    // get the layer
    SDL_Surface* loadedSurface = IMG_Load("hero.png");
    SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0xFF, 0, 0xFF ) );
    sprite = SDL_CreateTextureFromSurface(playRend, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    
    /*/////////////////////clips\\\\\\\\\\\\\\\\\\\\\\\\\*/
    
    /*///////////////UP\\\\\\\\\\\\\\*/
    clips[UP][0].x = 64;
    clips[UP][0].y = 0;
    clips[UP][0].h = 64;
    clips[UP][0].w = 64;
    
    clips[UP][1].x = 64;
    clips[UP][1].y = 64;
    clips[UP][1].h = 64;
    clips[UP][1].w = 64;
    
    clips[UP][2].x = 64;
    clips[UP][2].y = 128;
    clips[UP][2].h = 64;
    clips[UP][2].w = 64;
    
    clips[UP][3].x = 64;
    clips[UP][3].y = 192;
    clips[UP][3].h = 64;
    clips[UP][3].w = 64;
    /*///////////////UP\\\\\\\\\\\\\\*/
    
    /*///////////////DOWN\\\\\\\\\\\\\\*/
    clips[DOWN][0].x = 0;
    clips[DOWN][0].y = 0;
    clips[DOWN][0].h = 64;
    clips[DOWN][0].w = 64;
    
    clips[DOWN][1].x = 0;
    clips[DOWN][1].y = 64;
    clips[DOWN][1].h = 64;
    clips[DOWN][1].w = 64;
    
    clips[DOWN][2].x = 0;
    clips[DOWN][2].y = 128;
    clips[DOWN][2].h = 64;
    clips[DOWN][2].w = 64;
    
    clips[DOWN][3].x = 0;
    clips[DOWN][3].y = 192;
    clips[DOWN][3].h = 64;
    clips[DOWN][3].w = 64;
    /*///////////////DOWN\\\\\\\\\\\\\\*/
    
    /*///////////////LEFT\\\\\\\\\\\\\\*/
    clips[LEFT][0].x = 128;
    clips[LEFT][0].y = 0;
    clips[LEFT][0].h = 64;
    clips[LEFT][0].w = 64;
    
    clips[LEFT][1].x = 128;
    clips[LEFT][1].y = 64;
    clips[LEFT][1].h = 64;
    clips[LEFT][1].w = 64;
    
    clips[LEFT][2].x = 128;
    clips[LEFT][2].y = 128;
    clips[LEFT][2].h = 64;
    clips[LEFT][2].w = 64;
    
    clips[LEFT][3].x = 128;
    clips[LEFT][3].y = 192;
    clips[LEFT][3].h = 64;
    clips[LEFT][3].w = 64;
    /*///////////////LEFT\\\\\\\\\\\\\\*/
    
    /*///////////////RIGHT\\\\\\\\\\\\\\*/
    clips[RIGHT][0].x = 192;
    clips[RIGHT][0].y = 0;
    clips[RIGHT][0].h = 64;
    clips[RIGHT][0].w = 64;
    
    clips[RIGHT][1].x = 192;
    clips[RIGHT][1].y = 64;
    clips[RIGHT][1].h = 64;
    clips[RIGHT][1].w = 64;
    
    clips[RIGHT][2].x = 192;
    clips[RIGHT][2].y = 128;
    clips[RIGHT][2].h = 64;
    clips[RIGHT][2].w = 64;
    
    clips[RIGHT][3].x = 192;
    clips[RIGHT][3].y = 192;
    clips[RIGHT][3].h = 64;
    clips[RIGHT][3].w = 64;
    /*///////////////RIGHT\\\\\\\\\\\\\\*/
    
    /*/////////////////////clips\\\\\\\\\\\\\\\\\\\\\\\\\*/
    
    
    currRect = clips[DOWN][0];
    faceState = "down";
}

Player::~Player(){
    
}

void Player::setCurrRoom(Room room){
}

void Player::walk(std::string facing){
    if(facing == "down"){
        for(int i = 6; i < 18; i++){
            currRect = clips[DOWN][i/6];
                
            SDL_RenderClear(playRend);
            
            SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
            
            for(int i = 0; i < currRoom.monsterSize; i++){
                SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
            }
                
            SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
            
            SDL_RenderPresent(playRend);
            
        }
        
        currRect = clips[DOWN][0];
        
        SDL_RenderClear(playRend);
        
        SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
        
        for(int i = 0; i < currRoom.monsterSize; i++){
            SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
        }
        
        SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
        
        SDL_RenderPresent(playRend);
    }
    else if(facing == "up"){
        for(int i = 6; i < 18; i++){
            currRect = clips[UP][i/6];
            
            SDL_RenderClear(playRend);
            
            SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
            
            for(int i = 0; i < currRoom.monsterSize; i++){
                SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
            }
            
            SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
            
            SDL_RenderPresent(playRend);
        }
        
        currRect = clips[UP][0];
        
        SDL_RenderClear(playRend);
        
        SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
        
        for(int i = 0; i < currRoom.monsterSize; i++){
            SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
        }
        
        SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
        
        SDL_RenderPresent(playRend);
        
    }
    
    else if(facing == "left"){
        for(int i = 10; i < 30; i++){
            currRect = clips[LEFT][i/10];
            
            SDL_RenderClear(playRend);
            
            SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
            
            for(int i = 0; i < currRoom.monsterSize; i++){
                SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
            }
            
            SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
            
            SDL_RenderPresent(playRend);
        }
        
        currRect = clips[LEFT][0];
        
        SDL_RenderClear(playRend);
        
        SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
        
        for(int i = 0; i < currRoom.monsterSize; i++){
            SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
        }
        
        SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
        
        SDL_RenderPresent(playRend);
    }
    
    else if(facing == "right"){
        for(int i = 10; i < 30; i++){
            currRect = clips[RIGHT][i/10];
            
            SDL_RenderClear(playRend);
            
            SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
            
            for(int i = 0; i < currRoom.monsterSize; i++){
                SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
            }
            
            SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
            
            SDL_RenderPresent(playRend);
        }
        
        currRect = clips[RIGHT][0];
        
        SDL_RenderClear(playRend);
        
        SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
        
        for(int i = 0; i < currRoom.monsterSize; i++){
            SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
        }
        
        SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
        
        SDL_RenderPresent(playRend);
    }
}

void Player::hit(std::string facing){
    if(facing == "down"){
        for(int i = 0; i < 6; i++){
            currRect = clips[DOWN][3];
        
            SDL_RenderClear(playRend);
            
            SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
            
            for(int i = 0; i < currRoom.monsterSize; i++){
                SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
            }
        
            SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
        
            SDL_RenderPresent(playRend);
        }
        atkBox.h += 50;
        currRoom.detectAtk(atkBox, dmg);
        atkBox.h -= 50;
        
        currRect = clips[DOWN][0];
        
        SDL_RenderClear(playRend);
        
        SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
        
        for(int i = 0; i < currRoom.monsterSize; i++){
            SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
        }
        
        SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
        
        SDL_RenderPresent(playRend);
        
    }
    else if(facing == "up"){
        for(int i = 0; i < 6; i++){
            currRect = clips[UP][3];
        
            SDL_RenderClear(playRend);
            
            SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
            
            for(int i = 0; i < currRoom.monsterSize; i++){
                SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
            }
        
            SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
        
            SDL_RenderPresent(playRend);
        }
        atkBox.y -= 50;
        atkBox.h += 50;
        currRoom.detectAtk(atkBox, dmg);
        atkBox.y += 50;
        atkBox.h -= 50;
        
        currRect = clips[UP][0];
        
        SDL_RenderClear(playRend);
        
        SDL_RenderDrawRect(playRend, &atkBox);
        
        SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
        
        for(int i = 0; i < currRoom.monsterSize; i++){
            SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
        }
        
        SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
        
        SDL_RenderPresent(playRend);
    }
    
    else if(facing == "left"){
        for(int i = 0; i < 6; i++){
            currRect = clips[LEFT][3];
        
            SDL_RenderClear(playRend);
            
            SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
            
            for(int i = 0; i < currRoom.monsterSize; i++){
                SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
            }
        
            SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
        
            SDL_RenderPresent(playRend);
        }
        atkBox.x -= 50;
        atkBox.w += 50;
        currRoom.detectAtk(atkBox, dmg);
        atkBox.x += 50;
        atkBox.w -= 50;
        
        currRect = clips[LEFT][0];
        
        SDL_RenderClear(playRend);
        
        SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
        
        for(int i = 0; i < currRoom.monsterSize; i++){
            SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
        }
        
        SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
        
        SDL_RenderPresent(playRend);
    }
    
    else if(facing == "right"){
        for(int i = 0; i < 6; i++){
            currRect = clips[RIGHT][3];
        
            SDL_RenderClear(playRend);
            
            SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
            
            for(int i = 0; i < currRoom.monsterSize; i++){
                SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
            }
        
            SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
            
            SDL_RenderPresent(playRend);
        }
        atkBox.x += 50;
        atkBox.w += 50;
        currRoom.detectAtk(atkBox, dmg);
        atkBox.x -= 50;
        atkBox.w -= 50;
        
        currRect = clips[RIGHT][0];
        
        SDL_RenderClear(playRend);
        
        SDL_RenderCopy(playRend, currRoom.roomText, &currRoom.roomRect, &currRoom.roomOnRect);
        
        for(int i = 0; i < currRoom.monsterSize; i++){
            SDL_RenderCopy(playRend, currRoom.monsters[i].sprite, &currRoom.monsters[i].currRect, &currRoom.monsters[i].monLoc);
        }
        
        SDL_RenderCopy(playRend, sprite, &currRect, &playerLoc);
        
        SDL_RenderPresent(playRend);
    }
    SDL_Delay(100);
    
}

void Player::moveRightX(SDL_Rect rect, int speed){
    currRect = clips[RIGHT][0];
    playerLoc.x += speed/2;
    hBox.x += speed/2;
    atkBox.x += speed/2;
    faceState = "right";
    walk(faceState);
    playerLoc.x += speed/2;
    hBox.x += speed/2;
    atkBox.x += speed/2;
    
}

void Player::moveLeftX(SDL_Rect rect, int speed){
    currRect = clips[LEFT][0];
    playerLoc.x -= speed/2;
    hBox.x -= speed/2;
    atkBox.x -= speed/2;
    faceState = "left";
    walk(faceState);
    playerLoc.x -= speed/2;
    hBox.x -= speed/2;
    atkBox.x -= speed/2;
    
}

void Player::moveUpY(SDL_Rect rect, int speed){
    currRect = clips[UP][0];
    playerLoc.y -= speed/2;
    hBox.y -= speed/2;
    atkBox.y -= speed/2;
    faceState = "up";
    walk(faceState);
    playerLoc.y -= speed/2;
    hBox.y -= speed/2;
    atkBox.y -= speed/2;
    
}

void Player::moveDownY(SDL_Rect rect, int speed){
    currRect = clips[DOWN][0];
    playerLoc.y += speed/2;
    hBox.y += speed/2;
    atkBox.y += speed/2;
    faceState = "down";
    walk(faceState);
    playerLoc.y += speed/2;
    hBox.y += speed/2;
    atkBox.y += speed/2;

}

std::string Player::getFaceState(){
    return faceState;
}
