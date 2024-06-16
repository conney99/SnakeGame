#include "snakeGame.h"

//gate
void snakeGame::placeGate() //게이트 생성
{
    // 난수를 통해 idx를 받음
    int gate_idx1 = rand() % wall.size();
    int gate_idx2 = rand() % wall.size();
    while (gate_idx2 == gate_idx1) //중복되지않도록
    {
        gate_idx2 = rand() % wall.size();
    }
    gate_1 = wall[gate_idx1];
    gate_2 = wall[gate_idx2];
    start_color();
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    attron(COLOR_PAIR(5));
    move(gate_1.y, gate_1.x);
    addch(edgechar);
    move(gate_2.y, gate_2.x);
    addch(edgechar);
    attroff(COLOR_PAIR(5));
    refresh();
}

// Gate 위치 변경
void snakeGame::gateTime()
{
    gateTimer++;
    if (gateTimer % maxGateTime == 0)
    {
        attron(COLOR_PAIR(3));
        move(gate_1.y, gate_1.x);
        addch(edgechar);
        move(gate_2.y, gate_2.x);
        addch(edgechar);
        attroff(COLOR_PAIR(3));
        refresh();
        placeGate();
        gateTimer = 0;
    }
}

// Gate에 들어갔는지 확인
bool snakeGame::checkGate() {
    if (snake[0].x == gate_1.x && snake[0].y == gate_1.y) {
        gateTimer = maxGateTime - snake.size() - 1;
        scoreGate++;
        displayScore();
        return atGate1 = true;
    } else if (snake[0].x == gate_2.x && snake[0].y == gate_2.y) {
        gateTimer = maxGateTime - snake.size() - 1;
        scoreGate++;
        displayScore();
        return atGate2 = true;
    }

    return false; // 모든 조건이 만족하지 않을 때 false 반환
}



// 맵에 GrowthItem 표현
void snakeGame::placeGrowthItem()
{
    int tmpx, tmpy;
    bool clear = false;
    while (!clear)
    {
        tmpx = rand() % (maxWidth - 13) + 1;
        tmpy = rand() % (maxHeight - 2) + 1;
        clear = true;

        for (int i = 0; i < snake.size(); i++)
        {
            if (snake[i].x == tmpx && snake[i].y == tmpy)
            {
                clear = false;
                break;
            }
        }

        for (int i = 0; i < wall.size(); i++)
        {
            if (wall[i].x == tmpx && wall[i].y == tmpy)
            {
                clear = false;
                break;
            }
        }
    }

    growthItem.x = tmpx;
    growthItem.y = tmpy;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_GREEN);
    attron(COLOR_PAIR(1));
    move(growthItem.y, growthItem.x);
    addch(growthItemShape);
    attroff(COLOR_PAIR(1));
    refresh();
}

// GrowthItem 위치 변경
void snakeGame::growthItemTime()
{
    growthItemTimer++;
    if (growthItemTimer % maxItemTime == 0)
    {
        move(growthItem.y, growthItem.x);
        printw(" ");
        placeGrowthItem();
        growthItemTimer = 0;
    }
}

// GrowthItem 먹었는지 확인
bool snakeGame::checkGrowth()
{
    if (snake[0].x == growthItem.x && snake[0].y == growthItem.y)
    {
        growthItemTimer = 0;
        placeGrowthItem();
        currentLength++;
        scoreGrowthItem++;
        displayScore();
        return eatGrowthItem = true;
    }
    else
    {
        return eatGrowthItem = false;
    }
}


// 맵에 PoisonItem 표현
void snakeGame::placePoisonItem()
{
    int tmpx, tmpy;
    bool clear = false;
    while (!clear)
    {
        tmpx = rand() % (maxWidth - 13) + 1; 
        tmpy = rand() % (maxHeight - 2) + 1;
        clear = true;

        for (int i = 0; i < snake.size(); i++)
        {
            if (snake[i].x == tmpx && snake[i].y == tmpy)
            {
                clear = false;
                break;
            }
        }

        for (int i = 0; i < wall.size(); i++)
        {
            if (wall[i].x == tmpx && wall[i].y == tmpy)
            {
                clear = false;
                break;
            }
        }
    }
    poisonItem.x = tmpx;
    poisonItem.y = tmpy;
    start_color();
    init_pair(2, COLOR_WHITE, COLOR_RED);
    attron(COLOR_PAIR(2));
    move(poisonItem.y, poisonItem.x);
    addch(poisionItemShape);
    attroff(COLOR_PAIR(2));
    refresh();
}

// PoisonItem 위치 변경
void snakeGame::poisonItemTime() 
{
    poisonItemTimer++;
    if (poisonItemTimer % maxItemTime == 0)
    {
        move(poisonItem.y, poisonItem.x);
        printw(" ");
        placePoisonItem();
        poisonItemTimer = 0;
    }
}

// PoisonItem 먹었는지 확인
bool snakeGame::checkPoison()
{
    if (snake[0].x == poisonItem.x && snake[0].y == poisonItem.y)
    {
        poisonItemTimer = 0;
        placePoisonItem();
        currentLength--;
        scorePoisonItem++;
        displayScore();
        return eatPoisionItem = true;
    }
    else
    {
        return eatPoisionItem = false;
    }
}


// 맵에 SpeedItem 표현
void snakeGame::placeSpeedItem()
{
    int tmpx, tmpy;
    bool clear = false;
    while (!clear)
    {
        tmpx = rand() % (maxWidth - 13) + 1; 
        tmpy = rand() % (maxHeight - 2) + 1;
        clear = true;

        for (int i = 0; i < snake.size(); i++)
        {
            if (snake[i].x == tmpx && snake[i].y == tmpy)
            {
                clear = false;
                break;
            }
        }

        for (int i = 0; i < wall.size(); i++)
        {
            if (wall[i].x == tmpx && wall[i].y == tmpy)
            {
                clear = false;
                break;
            }
        }
    }
    speedItem.x = tmpx;
    speedItem.y = tmpy;
    start_color();
    init_pair(6, COLOR_WHITE, COLOR_YELLOW);
    attron(COLOR_PAIR(6));
    move(speedItem.y, speedItem.x);
    addch(speedItemShape);
    attroff(COLOR_PAIR(6));
    refresh();
}

// SpeedItem 위치 변경
void snakeGame::speedItemTime() 
{
    speedItemTimer++;
    if (speedItemTimer % maxItemTime == 0)
    {
        move(speedItem.y, speedItem.x);
        printw(" ");
        placeSpeedItem();
        speedItemTimer = 0;
    }
}

// SpeedItem 먹었는지 확인
void snakeGame::checkSpeed()
{
    if (snake[0].x == speedItem.x && snake[0].y == speedItem.y)
    {
        speedItemTimer = 0;
        placeSpeedItem();
        snakeSpeed -= 10000;
        scoreSpeedItem++;
        displayScore();
    }
}
