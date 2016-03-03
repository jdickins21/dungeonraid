//
//  main.cpp
//  Dungeon Raid
//
//  Created by Jacob Dickinson on 2/15/15.
//  Copyright (c) 2015 Jacob Dickinson. All rights reserved.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include"player.h"
#include "cave.h"


int main(int argc, const char * argv[]){
    /*/////////////////SCREEN\\\\\\\\\\\\\\\\\\\\\\\\\\*/
    //Main loop flag
    bool quit = false;
    
    SDL_Window *window = SDL_CreateWindow("Title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_SHOWN );
    int* winWidth;
    int* winHeight;
    SDL_GetWindowSize(window, winWidth, winHeight);
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
    
    //Event handler
    SDL_Event e;
    
    /*/////////////////MAP\\\\\\\\\\\\\\\\\\\\\*/
    Cave cave(window, renderer);
    
    /*/////////////////PLAYER\\\\\\\\\\\\\\\\\\\\\*/
    Player player(window, renderer);
    player.currRoom = cave.currMap;
    
    //While application is running
    while( !quit ){
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ){
            //User requests quit
            if( e.type == SDL_QUIT ){
                quit = true;
            }
        }
        const Uint8* currentLeyState = SDL_GetKeyboardState(NULL);
        if(currentLeyState[SDL_SCANCODE_UP]){
            if(currentLeyState[SDL_SCANCODE_SPACE]){
                player.hit(player.getFaceState());
            }
            player.moveUpY(player.currRect, player.speed);
            if(player.hBox.y < 0){
                cave.changeRoom(cave.currMap, 2, 0, &player.playerLoc.x, &player.playerLoc.y, &player.hBox.x, &player.hBox.y, &player.atkBox.x, &player.atkBox.y);
                player.currRoom = cave.currMap;
            }
            if(cave.currMap.detectCollision(player.hBox)){
                player.playerLoc.y += (player.speed + 3);
                player.hBox.y += (player.speed + 3);
            }
            else{
                if(cave.currMap.roomRect.y > 0){
                    cave.currMap.moveUp(16);
                    cave.currMap.roomRect.y -= 16;
                    player.currRoom = cave.currMap;
                }
            }
        }
        else if(currentLeyState[SDL_SCANCODE_DOWN]){
            if(currentLeyState[SDL_SCANCODE_SPACE]){
                player.hit(player.getFaceState());
            }
            player.moveDownY(player.currRect, player.speed);
            if(player.hBox.y > *winHeight){
                cave.changeRoom(cave.currMap, 2, 1, &player.playerLoc.x, &player.playerLoc.y, &player.hBox.x, &player.hBox.y, &player.atkBox.x, &player.atkBox.y);
                player.currRoom = cave.currMap;
            }
            if(cave.currMap.detectCollision(player.hBox)){
                player.playerLoc.y -= (player.speed + 3);
                player.hBox.y -= (player.speed + 3);
            }
            else{
                if(cave.currMap.roomRect.y < (cave.currMap.height - 500)){
                    cave.currMap.moveDown(16);
                    cave.currMap.roomRect.y += 16;
                    player.currRoom = cave.currMap;
                }
            }
        }
        else if(currentLeyState[SDL_SCANCODE_LEFT]){
            if(currentLeyState[SDL_SCANCODE_SPACE]){
                player.hit(player.getFaceState());
            }
            player.moveLeftX(player.currRect, player.speed);
            if(player.hBox.x < 0){
                cave.changeRoom(cave.currMap, 0, 2, &player.playerLoc.x, &player.playerLoc.y, &player.hBox.x, &player.hBox.y, &player.atkBox.x, &player.atkBox.y);
                player.currRoom = cave.currMap;
            }
            if(cave.currMap.detectCollision(player.hBox)){
                player.playerLoc.x += (player.speed + 3);
                player.hBox.x += (player.speed + 3);
            }
            else{
                if(cave.currMap.roomRect.x > 0){
                    cave.currMap.moveLeft(16);
                    cave.currMap.roomRect.x -= 16;
                    player.currRoom = cave.currMap;
                }
            }
        }
        else if(currentLeyState[SDL_SCANCODE_RIGHT]){
            if(currentLeyState[SDL_SCANCODE_SPACE]){
                player.hit(player.getFaceState());
            }
            player.moveRightX(player.currRect, player.speed);
            if(player.hBox.x > *winWidth){
                cave.changeRoom(cave.currMap, 1, 2, &player.playerLoc.x, &player.playerLoc.y, &player.hBox.x, &player.hBox.y, &player.atkBox.x, &player.atkBox.y);
                player.currRoom = cave.currMap;
            }
            if(cave.currMap.detectCollision(player.hBox)){
                player.playerLoc.x -= (player.speed + 3);
                player.hBox.x -= (player.speed + 3);
            }
            else{
                if(cave.currMap.roomRect.x < (cave.currMap.width - 500)){
                    cave.currMap.moveRight(16);
                    cave.currMap.roomRect.x += 16;
                    player.currRoom = cave.currMap;
                }
            }
        }
        else if(currentLeyState[SDL_SCANCODE_SPACE]){
            player.hit(player.getFaceState());
        }
        SDL_RenderClear(renderer);
        
        SDL_RenderCopy(renderer, cave.currMap.roomText, &cave.currMap.roomRect, &cave.currMap.roomOnRect);
        for(int i = 0; i < cave.currMap.monsterSize; i++){
            SDL_RenderCopy(renderer, cave.currMap.monsters[i].sprite, &cave.currMap.monsters[i].currRect, &cave.currMap.monsters[i].monLoc);
        }
        
        SDL_RenderCopy(renderer, player.sprite, &player.currRect, &player.playerLoc);
        
        SDL_RenderPresent(renderer);
        
    }
    SDL_Quit();
    return 0;
};

