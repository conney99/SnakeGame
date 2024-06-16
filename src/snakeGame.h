#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

#ifndef SNAKEGAME_H
#define SNAKEGAME_H

struct CharPosition
{
    int x, y;
    CharPosition(int col, int row);
    CharPosition();
};

class snakeGame
{
private:
    int snakeSpeed, maxWidth, maxHeight, maxGateTime, maxItemTime;

    //key
    int rightKey, leftKey, upKey, downKey;

    char direction, snakeShape, edgechar, growthItemShape, poisionItemShape, speedItemShape;

    //score
    int scoreGrowthItem, scorePoisonItem, scoreGate, scoreSpeedItem, currentLength;

    //Item Timer
    int growthItemTimer, poisonItemTimer, speedItemTimer, gateTimer; 

    //required to next stage
    int requiredLength, requiredGrowthItem, requiredPoisonItem, requiredGate, requiredSpeedItem;

    bool eatGrowthItem, eatPoisionItem, atGate1, atGate2;
    CharPosition growthItem, poisonItem, speedItem; 
    std::vector<CharPosition> snake;                
    std::vector<CharPosition> wall;
    CharPosition gate_1, gate_2;
    bool isClear;

    //get key
    void getKey();

    //window
    void setWindow(int level);
    void renderWindow(int level);
    
    void renderSnake();
    void displayScore();
    bool nextStage();

    //bool CheckNextStage();

    //gate
    void placeGate();
    bool checkGate();
    void gateTime();

    //groth
    void placeGrowthItem();
    bool checkGrowth();
    void growthItemTime();

    //poison
    void placePoisonItem();
    bool checkPoison();
    void poisonItemTime();

    //speed
    void placeSpeedItem();
    void checkSpeed();
    void speedItemTime();

    //game over situations
    bool checkCollision();

    char getWarpDirection(char d, CharPosition gate);

    //snake
    void moveSnake();

public:
    snakeGame(int level);
    ~snakeGame(); 
    void runGame();
    bool getClear();
};

#endif
