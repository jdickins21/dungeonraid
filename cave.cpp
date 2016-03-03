//
//  cave.cpp
//  Dungeon Raid
//
//  Created by Jacob Dickinson on 3/3/15.
//  Copyright (c) 2015 Jacob Dickinson. All rights reserved.
//

#include "cave.h"



Cave::Cave(SDL_Window* window, SDL_Renderer* mapRend){
    
    
    /*/////////////////////ROOMS\\\\\\\\\\\\\\\\\\\\\\\\\\*/
    roomOne.ID = 1;
    roomOne.height = 500;
    roomOne.width = 500;
    roomOne.roomText = IMG_LoadTexture(mapRend, "area1.png");
    roomOne.boxes = new SDL_Rect[0];
    roomOne.roomRect.h = 500;
    roomOne.roomRect.w = 500;
    roomOne.roomRect.x = 0;
    roomOne.roomRect.y = 0;
    roomOne.roomOnRect = roomOne.roomRect;
    SDL_Rect oneRectOne;
    oneRectOne.x = 0;
    oneRectOne.y = 0;
    oneRectOne.w = 61;
    oneRectOne.h = 182;
    roomOne.hitBox.push_back(oneRectOne);
    SDL_Rect oneRectTwo;
    oneRectTwo.x = 0;
    oneRectTwo.y = 260;
    oneRectTwo.w = 61;
    oneRectTwo.h = 248;
    roomOne.hitBox.push_back(oneRectTwo);
    SDL_Rect oneRectThree;
    oneRectThree.x = 61;
    oneRectThree.y = 0;
    oneRectThree.w = 125;
    oneRectThree.h = 52;
    roomOne.hitBox.push_back(oneRectThree);
    SDL_Rect oneRectFour;
    oneRectFour.x = 257;
    oneRectFour.y = 0;
    oneRectFour.w = 181;
    oneRectFour.h = 52;
    roomOne.hitBox.push_back(oneRectFour);
    SDL_Rect oneRectFive;
    oneRectFive.x = 435;
    oneRectFive.y = 0;
    oneRectFive.w = 73;
    oneRectFive.h = 500;
    roomOne.hitBox.push_back(oneRectFive);
    SDL_Rect oneRectSix;
    oneRectSix.x = 65;
    oneRectSix.y = 435;
    oneRectSix.w = 381;
    oneRectSix.h = 67;
    roomOne.hitBox.push_back(oneRectSix);
    
    roomTwo.ID = 2;
    roomTwo.height = 500;
    roomTwo.width = 750;
    roomTwo.roomText = IMG_LoadTexture(mapRend, "area2.png");
    roomTwo.size = 3;
    roomTwo.boxes = new SDL_Rect[roomTwo.size];
    roomTwo.monsterSize = 1;
    roomTwo.monsters = new Monster[roomTwo.monsterSize];
    roomTwo.roomRect.h = 500;
    roomTwo.roomRect.w = 500;
    roomTwo.roomRect.x = 250;
    roomTwo.roomRect.y = 0;
    roomTwo.roomOnRect.h = 500;
    roomTwo.roomOnRect.w = 500;
    roomTwo.roomOnRect.x = 0;
    roomTwo.roomOnRect.y = 0;
    SDL_Rect twoRectOne;
    twoRectOne.x = 0;
    twoRectOne.y = 0;
    twoRectOne.w = 62;
    twoRectOne.h = 500;
    roomTwo.hitBox.push_back(twoRectOne);
    SDL_Rect twoRectTwo;
    twoRectTwo.x = 62;
    twoRectTwo.y = 0;
    twoRectTwo.w = 290;
    twoRectTwo.h = 55;
    roomTwo.hitBox.push_back(twoRectTwo);
    SDL_Rect twoRectThree;
    twoRectThree.x = 87;
    twoRectThree.y = 0;
    twoRectThree.w = 413;
    twoRectThree.h = 211;
    roomTwo.boxes[0] = twoRectThree;
    SDL_Rect twoRectFour;
    twoRectFour.x = 99;
    twoRectFour.y = 291;
    twoRectFour.w = 410;
    twoRectFour.h = 209;
    roomTwo.boxes[1] = twoRectFour;
    SDL_Rect twoRectFive;
    twoRectFive.x = 62;
    twoRectFive.y = 444;
    twoRectFive.w = 293;
    twoRectFive.h = 61;
    roomTwo.hitBox.push_back(twoRectFive);
    Monster goblin(mapRend, -64, 250);
    roomTwo.monsters[0] = goblin;
    roomTwo.boxes[2] = goblin.hBox;
    
    roomThree.ID = 3;
    roomThree.height = 750;
    roomThree.width = 750;
    roomThree.roomText = IMG_LoadTexture(mapRend, "area3.png");
    roomThree.size = 5;
    roomThree.boxes = new SDL_Rect[roomThree.size];
    roomThree.roomRect.h = 500;
    roomThree.roomRect.w = 500;
    roomThree.roomRect.x = 0;
    roomThree.roomRect.y = 0;
    roomThree.roomOnRect.h = 500;
    roomThree.roomOnRect.w = 500;
    roomThree.roomOnRect.x = 0;
    roomThree.roomOnRect.y = 0;
    SDL_Rect threeRectOne;
    threeRectOne.x = 437;
    threeRectOne.y = 25;
    threeRectOne.w = 60;
    threeRectOne.h = 483;
    roomThree.boxes[0] = threeRectOne;
    SDL_Rect threeRectTwo;
    threeRectTwo.x = -250;
    threeRectTwo.y = 361;
    threeRectTwo.w = 613;
    threeRectTwo.h = 144;
    roomThree.boxes[1] = threeRectTwo;
    SDL_Rect threeRectThree;
    threeRectThree.x = -250;
    threeRectThree.y = -250;
    threeRectThree.w = 64;
    threeRectThree.h = 616;
    roomThree.boxes[2] = threeRectThree;
    SDL_Rect threeRectFour;
    threeRectFour.x = -250;
    threeRectFour.y = -250;
    threeRectFour.w = 750;
    threeRectFour.h = 41;
    roomThree.boxes[3] = threeRectFour;
    SDL_Rect threeRectFive;
    threeRectFive.x = 436;
    threeRectFive.y = -204;
    threeRectFive.w = 58;
    threeRectFive.h = 154;
    roomThree.boxes[4] = threeRectFive;
    
    roomFour.ID = 4;
    roomFour.height = 500;
    roomFour.width = 500;
    roomFour.roomText = IMG_LoadTexture(mapRend, "area4.png");
    roomFour.roomRect.h = 500;
    roomFour.roomRect.w = 500;
    roomFour.roomRect.x = 0;
    roomFour.roomRect.y = 0;
    roomFour.roomOnRect = roomFour.roomRect;
    SDL_Rect fourRectOne;
    fourRectOne.x = 0;
    fourRectOne.y = 0;
    fourRectOne.w = 61;
    fourRectOne.h = 81;
    roomFour.hitBox.push_back(fourRectOne);
    SDL_Rect fourRectTwo;
    fourRectTwo.x = 0;
    fourRectTwo.y = 0;
    fourRectTwo.w = 304;
    fourRectTwo.h = 43;
    roomFour.hitBox.push_back(fourRectTwo);
    SDL_Rect fourRectThree;
    fourRectThree.x = 365;
    fourRectThree.y = 0;
    fourRectThree.w = 139;
    fourRectThree.h = 53;
    roomFour.hitBox.push_back(fourRectThree);
    SDL_Rect fourRectFour;
    fourRectFour.x = 439;
    fourRectFour.y = 0;
    fourRectFour.w = 61;
    fourRectFour.h = 500;
    roomFour.hitBox.push_back(fourRectFour);
    SDL_Rect fourRectFive;
    fourRectFive.x = 0;
    fourRectFive.y = 446;
    fourRectFive.w = 500;
    fourRectFive.h = 54;
    roomFour.hitBox.push_back(fourRectFive);
    SDL_Rect fourRectSix;
    fourRectSix.x = 0;
    fourRectSix.y = 164;
    fourRectSix.w = 60;
    fourRectSix.h = 336;
    roomFour.hitBox.push_back(fourRectSix);
    SDL_Rect fourRectSeven;
    fourRectSeven.x = 94;
    fourRectSeven.y = 261;
    fourRectSeven.w = 126;
    fourRectSeven.h = 57;
    roomFour.hitBox.push_back(fourRectSeven);
    SDL_Rect fourRectEight;
    fourRectEight.x = 185;
    fourRectEight.y = 88;
    fourRectEight.w = 73;
    fourRectEight.h = 98;
    roomFour.hitBox.push_back(fourRectEight);
    SDL_Rect fourRectNine;
    fourRectNine.x = 257;
    fourRectNine.y = 131;
    fourRectNine.w = 61;
    fourRectNine.h = 63;
    roomFour.hitBox.push_back(fourRectNine);
    SDL_Rect fourRectTen;
    fourRectTen.x = 276;
    fourRectTen.y = 192;
    fourRectTen.w = 43;
    fourRectTen.h = 187;
    roomFour.hitBox.push_back(fourRectTen);
    
    roomFive.ID = 5;
    roomFive.height = 750;
    roomFive.width = 500;
    roomFive.roomText = IMG_LoadTexture(mapRend, "area5.png");
    roomFive.size = 9;
    roomFive.boxes = new SDL_Rect[roomFive.size];
    roomFive.roomRect.h = 500;
    roomFive.roomRect.w = 500;
    roomFive.roomRect.x = 0;
    roomFive.roomRect.y = 0;
    roomFive.roomOnRect.h = 500;
    roomFive.roomOnRect.w = 500;
    roomFive.roomOnRect.x = 0;
    roomFive.roomOnRect.y = 0;
    SDL_Rect fiveRectOne;
    fiveRectOne.x = 0;
    fiveRectOne.y = 48;
    fiveRectOne.w = 70;
    fiveRectOne.h = 455;
    roomFive.boxes[0] = fiveRectOne;
    SDL_Rect fiveRectTwo;
    fiveRectTwo.x = 0;
    fiveRectTwo.y = -250;
    fiveRectTwo.w = 63;
    fiveRectTwo.h = 244;
    roomFive.boxes[1] = fiveRectTwo;
    SDL_Rect fiveRectThree;
    fiveRectThree.x = 0;
    fiveRectThree.y = -250;
    fiveRectThree.w = 500;
    fiveRectThree.h = 55;
    roomFive.boxes[2] = fiveRectThree;
    SDL_Rect fiveRectFour;
    fiveRectFour.x = 436;
    fiveRectFour.y = -250;
    fiveRectFour.w = 67;
    fiveRectFour.h = 750;
    roomFive.boxes[3] = fiveRectFour;
    SDL_Rect fiveRectFive;
    fiveRectFive.x = 370;
    fiveRectFive.y = 432;
    fiveRectFive.w = 130;
    fiveRectFive.h = 60;
    roomFive.boxes[4] = fiveRectFive;
    SDL_Rect fiveRectSix;
    fiveRectSix.x = 122;
    fiveRectSix.y = 199;
    fiveRectSix.w = 82;
    fiveRectSix.h = 170;
    roomFive.boxes[5] = fiveRectSix;
    SDL_Rect fiveRectSeven;
    fiveRectSeven.x = 0;
    fiveRectSeven.y = 431;
    fiveRectSeven.w = 299;
    fiveRectSeven.h = 70;
    roomFive.boxes[6] = fiveRectSeven;
    SDL_Rect fiveRectEight;
    fiveRectEight.x = 144;
    fiveRectEight.y = 184;
    fiveRectEight.w = 332;
    fiveRectEight.h = 75;
    roomFive.boxes[7] = fiveRectEight;
    SDL_Rect fiveRectNine;
    fiveRectNine.x = 290;
    fiveRectNine.y = -250;
    fiveRectNine.w = 81;
    fiveRectNine.h = 353;
    roomFive.boxes[8] = fiveRectNine;

    
    roomSix.ID = 6;
    roomSix.height = 500;
    roomSix.width = 750;
    roomSix.roomText = IMG_LoadTexture(mapRend, "area6.png");
    roomSix.size = 7;
    roomSix.boxes = new SDL_Rect[roomSix.size];
    roomSix.roomRect.h = 500;
    roomSix.roomRect.w = 500;
    roomSix.roomRect.x = 0;
    roomSix.roomRect.y = 0;
    roomSix.roomOnRect.h = 500;
    roomSix.roomOnRect.w = 500;
    roomSix.roomOnRect.x = 0;
    roomSix.roomOnRect.y = 0;
    SDL_Rect sixRectOne;
    sixRectOne.x = -250;
    sixRectOne.y = 0;
    sixRectOne.w = 52;
    sixRectOne.h = 500;
    roomSix.boxes[0] = sixRectOne;
    SDL_Rect sixRectTwo;
    sixRectTwo.x = -250;
    sixRectTwo.y = 0;
    sixRectTwo.w = 130;
    sixRectTwo.h = 139;
    roomSix.boxes[1] = sixRectTwo;
    SDL_Rect sixRectThree;
    sixRectThree.x = -250;
    sixRectThree.y = 0;
    sixRectThree.w = 750;
    sixRectThree.h = 50;
    roomSix.boxes[2] = sixRectThree;
    SDL_Rect sixRectFour;
    sixRectFour.x = 444;
    sixRectFour.y = 0;
    sixRectFour.w = 56;
    sixRectFour.h = 69;
    roomSix.boxes[3] = sixRectFour;
    SDL_Rect sixRectFive;
    sixRectFive.x = -250;
    sixRectFive.y = 444;
    sixRectFive.w = 750;
    sixRectFive.h = 56;
    roomSix.boxes[4] = sixRectFive;
    SDL_Rect sixRectSix;
    sixRectSix.x = 244;
    sixRectSix.y = 276;
    sixRectSix.w = 255;
    sixRectSix.h = 224;
    roomSix.boxes[5] = sixRectSix;
    SDL_Rect sixRectSeven;
    sixRectSeven.x = 430;
    sixRectSeven.y = 154;
    sixRectSeven.w = 70;
    sixRectSeven.h = 144;
    roomSix.boxes[6] = sixRectSeven;
    
    

    /*/////////////////////ROOMS\\\\\\\\\\\\\\\\\\\\\\\\\\*/
    currMap = roomOne;
    
    
    
    
}

Cave::~Cave(){
    
}

void Cave::changeRoom(Room room, int x, int y, int* playerX, int* playerY, int* playhX, int* plahY, int* playatx, int* playaty){
    if(room.ID == 1){
        if(x == 0){
            currMap = roomTwo;
            *playerX = 452;
            *playerY = 207;
            *playhX = 472;
            *plahY = 248;
        }
        
        else if (y == 0){
            roomThree.roomRect.x = 250;
            roomThree.roomRect.y = 250;
            
            roomThree.boxes[0].x = 437;
            roomThree.boxes[0].y = 25;
            
            roomThree.boxes[1].x = -250;
            roomThree.boxes[1].y = 361;
            
            roomThree.boxes[2].x = -250;
            roomThree.boxes[2].y = -250;
            
            roomThree.boxes[3].x = -250;
            roomThree.boxes[3].y = -250;
            
            roomThree.boxes[4].x = 436;
            roomThree.boxes[4].y = -204;
            currMap = roomThree;
            *playerX = 395;
            *playerY = 398;
            *playhX = 415;
            *plahY = 439;
            *playatx = 423;
            *playaty = 424;
        }
    }
    if(room.ID == 2){
        if(x == 1){
            currMap = roomOne;
            *playerX = 0;
            *playerY = 198;
            *playhX = 20;
            *plahY = 239;
            *playatx = 28;
            *playaty = 224;
        }
    }
    if(room.ID == 3){
        if(y == 1){
            currMap = roomOne;
            *playerX = 197;
            *playerY = 9;
            *playhX = 217;
            *plahY = 50;
            *playatx = 225;
            *playaty = 37;
        }
        
        else if(x == 1){
            currMap = roomFour;
            *playerX = 0;
            *playerY = 70;
            *playhX = 20;
            *plahY = 111;
            *playatx = 28;
            *playaty = 96;
            
        }
    }
    if(room.ID ==4){
        if(x == 0){
            roomThree.roomRect.x = 250;
            roomThree.roomRect.y = 250;
            
            roomThree.boxes[0].x = 437;
            roomThree.boxes[0].y = 275;
            
            roomThree.boxes[1].x = -250;
            roomThree.boxes[1].y = 611;
            
            roomThree.boxes[2].x = -250;
            roomThree.boxes[2].y = 0;
            
            roomThree.boxes[3].x = -250;
            roomThree.boxes[3].y = 0;
            
            roomThree.boxes[4].x = 436;
            roomThree.boxes[4].y = 40;
            
            roomThree.roomRect.x = 250;
            roomThree.roomRect.y = 0;
            currMap = roomThree;
            *playerX = 450;
            *playerY = 156;
            *playhX = 470;
            *plahY = 197;
            *playatx = 578;
            *playaty = 182;
        }
        
        else if(y == 0){
            roomFive.roomRect.y = 250;
            
            roomFive.boxes[0].x = 0;
            roomFive.boxes[0].y = 48;
            
            roomFive.boxes[1].x = 0;
            roomFive.boxes[1].y = -250;
            
            roomFive.boxes[2].x = 0;
            roomFive.boxes[2].y = -250;
            
            roomFive.boxes[3].x = 436;
            roomFive.boxes[3].y = -250;
            
            roomFive.boxes[4].x = 370;
            roomFive.boxes[4].y = 432;
            
            roomFive.boxes[5].x = 122;
            roomFive.boxes[5].y = 199;
            
            roomFive.boxes[6].x = 0;
            roomFive.boxes[6].y = 431;
            
            roomFive.boxes[7].x = 144;
            roomFive.boxes[7].y = 184;
            
            roomFive.boxes[8].x = 290;
            roomFive.boxes[8].y = -250;
            
            currMap = roomFive;
            *playerX = 300;
            *playerY = 425;
            *playhX = 320;
            *plahY = 466;
            *playatx = 328;
            *playaty = 451;
        }
    }
    if(room.ID == 5){
        if(y == 1){
            currMap = roomFour;
            *playerX = 305;
            *playerY = 0;
            *playhX = 325;
            *plahY = 500;
            *playatx = 333;
            *playaty = 26;
        }
        
        else if(x == 0){
            roomSix.roomRect.x = 250;
            currMap = roomSix;
            *playerX = 475;
            *playerY = 90;
            *playhX = 495;
            *plahY = 131;
            *playatx = 503;
            *playaty = 116;
        }
    }
    if(room.ID == 6){
        if(x == 1){
            roomFive.roomRect.y = 0;
            
            roomFive.boxes[0].x = 0;
            roomFive.boxes[0].y = 298;
            
            roomFive.boxes[1].x = 0;
            roomFive.boxes[1].y = 0;
            
            roomFive.boxes[2].x = 0;
            roomFive.boxes[2].y = 0;
            
            roomFive.boxes[3].x = 436;
            roomFive.boxes[3].y = 0;
            
            roomFive.boxes[4].x = 370;
            roomFive.boxes[4].y = 682;
            
            roomFive.boxes[5].x = 122;
            roomFive.boxes[5].y = 449;
            
            roomFive.boxes[6].x = 0;
            roomFive.boxes[6].y = 681;
            
            roomFive.boxes[7].x = 144;
            roomFive.boxes[7].y = 434;
            
            roomFive.boxes[8].x = 290;
            roomFive.boxes[8].y = 0;
            
            currMap = roomFive;
            *playerX = 0;
            *playerY = 236;
            *playhX = 56;
            *plahY = 277;
            *playatx = 28;
            *playaty = 262;
        }
    }
}
