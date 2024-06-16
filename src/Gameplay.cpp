#include "snakeGame.h"
#include <unistd.h>

int KeyPressed;

//다음 스테이지로 넘어가는 기준 확인
bool snakeGame::nextStage()
{
    if (currentLength >= requiredLength && scoreGrowthItem >= requiredGrowthItem && scorePoisonItem >= requiredPoisonItem && scoreGate >= requiredGate && scoreSpeedItem >= requiredSpeedItem)
    {
        return true;
    }
    return false;
}

// Snake 움직임 정의
void snakeGame::moveSnake()
{
    KeyPressed = getch();
    if (KeyPressed == leftKey) {
        if (direction != 'r')
        {
            direction = 'l';
        }
        else
            checkCollision();
    }
    else if (KeyPressed == rightKey) {
        if (direction != 'l')
        {
            direction = 'r';
        }
        else
            checkCollision();
    }
    else if (KeyPressed == upKey) {
        if (direction != 'd')
        {
            direction = 'u';
        }
        else
            checkCollision();
    }
    else if (KeyPressed == downKey) {
        if (direction != 'u')
        {
            direction = 'd';
        }
        else
            checkCollision();
    }
    else if (KeyPressed == KEY_BACKSPACE)
        direction = 'q';

    if (!(eatGrowthItem || eatPoisionItem))
    {
        move(snake[snake.size() - 1].y, snake[snake.size() - 1].x); 
        printw(" ");                                               
        refresh();
        snake.pop_back(); 
    }
    else if (eatPoisionItem) 
    {
        move(snake[snake.size() - 1].y, snake[snake.size() - 1].x);
        printw(" ");
        snake.pop_back();
        move(snake[snake.size() - 1].y, snake[snake.size() - 1].x);
        printw(" ");
        refresh();
        snake.pop_back();
    }

    if (direction == 'l')
    {
        snake.insert(snake.begin(), CharPosition(snake[0].x - 1, snake[0].y));
    }
    else if (direction == 'r')
    {
        snake.insert(snake.begin(), CharPosition(snake[0].x + 1, snake[0].y));
    }
    else if (direction == 'u')
    {
        snake.insert(snake.begin(), CharPosition(snake[0].x, snake[0].y - 1));
    }
    else if (direction == 'd')
    {
        snake.insert(snake.begin(), CharPosition(snake[0].x, snake[0].y + 1));
    }

    if (atGate1)
    {
        atGate1 = false;
        direction = getWarpDirection(direction, gate_2);
        if (direction == 'r')
        {
            snake[0] = CharPosition(gate_2.x + 1, gate_2.y);
        }
        else if (direction == 'l')
        {
            snake[0] = CharPosition(gate_2.x - 1, gate_2.y);
        }
        else if (direction == 'd')
        {
            snake[0] = CharPosition(gate_2.x, gate_2.y + 1);
        }
        else if (direction == 'u')
        {
            snake[0] = CharPosition(gate_2.x, gate_2.y - 1);
        }
    }
    else if (atGate2)
    {
        atGate2 = false;
        direction = getWarpDirection(direction, gate_1);
        if (direction == 'r')
        {
            snake[0] = CharPosition(gate_1.x + 1, gate_1.y);
        }
        else if (direction == 'l')
        {
            snake[0] = CharPosition(gate_1.x - 1, gate_1.y);
        }
        else if (direction == 'd')
        {
            snake[0] = CharPosition(gate_1.x, gate_1.y + 1);
        }
        else if (direction == 'u')
        {
            snake[0] = CharPosition(gate_1.x, gate_1.y - 1);
        }
    }


    move(snake[0].y, snake[0].x);
    addch(snakeShape); 
    refresh();
    return;
}

// 게이트를 통과할 때
char snakeGame::getWarpDirection(char d, CharPosition gate)
{
    char result;
    CharPosition leftBlock(gate.x - 1, gate.y);
    CharPosition rightBlock(gate.x + 1, gate.y);
    CharPosition upBlock(gate.x, gate.y - 1);
    CharPosition downBlock(gate.x, gate.y + 1);

    bool isLeftWall = false;
    bool isRightWall = false;
    bool isUpWall = false;
    bool isDownWall = false;

    for (int i = 0; i < wall.size(); i++)
    {
        if (wall[i].x == leftBlock.x && wall[i].y == leftBlock.y)
        {
            isLeftWall = true;
        }
        if (wall[i].x == rightBlock.x && wall[i].y == rightBlock.y)
        {
            isRightWall = true;
        }
        if (wall[i].x == upBlock.x && wall[i].y == upBlock.y)
        {
            isUpWall = true;
        }
        if (wall[i].x == downBlock.x && wall[i].y == downBlock.y)
        {
            isDownWall = true;
        }
    }

    if ((leftBlock.x == 0 && leftBlock.y == 0) || (leftBlock.x == 0 && leftBlock.y == maxHeight - 1))
    {
        isLeftWall = true;
    }
    if ((rightBlock.x == maxWidth - 12 && rightBlock.y == 0) || (rightBlock.x == maxWidth - 12 && rightBlock.y == maxHeight - 1))
    {
        isRightWall = true;
    }
    if ((upBlock.x == 0 && upBlock.y == 0) || (upBlock.x == maxWidth - 12 && upBlock.y == 0))
    {
        isUpWall = true;
    }
    if ((downBlock.x == 0 && downBlock.y == maxHeight - 1) || (downBlock.x == maxWidth - 12 && downBlock.y == maxHeight - 1))
    {
        isDownWall = true;
    }

    if (gate.x == 0)
    {
        isLeftWall = true;
        isUpWall = true;
        isDownWall = true;
    }
    if (gate.x == maxWidth - 12)
    {
        isRightWall = true;
        isUpWall = true;
        isDownWall = true;
    }
    if (gate.y == 0)
    {
        isUpWall = true;
        isRightWall = true;
        isLeftWall = true;
    }
    if (gate.y == maxHeight - 1)
    {
        isDownWall = true;
        isRightWall = true;
        isLeftWall = true;
    }

    if (d == 'l')
    {
        if (!isLeftWall)
        {
            result = 'l';
        }
        else if (!isUpWall)
        {
            result = 'u';
        }
        else if (!isRightWall)
        {
            result = 'r';
        }
        else
        {
            result = 'd';
        }
    }

    if (d == 'u')
    {
        if (!isUpWall)
        {
            result = 'u';
        }
        else if (!isRightWall)
        {
            result = 'r';
        }
        else if (!isDownWall)
        {
            result = 'd';
        }
        else
        {
            result = 'l';
        }
    }

    if (d == 'r')
    {
        if (!isRightWall)
        {
            result = 'r';
        }
        else if (!isDownWall)
        {
            result = 'd';
        }
        else if (!isLeftWall)
        {
            result = 'l';
        }
        else
        {
            result = 'u';
        }
    }

    if (d == 'd')
    {
        if (!isDownWall)
        {
            result = 'd';
        }
        else if (!isLeftWall)
        {
            result = 'l';
        }
        else if (!isUpWall)
        {
            result = 'u';
        }
        else
        {
            result = 'r';
        }
    }
    return result;
}


// 게임 종료 조건
bool snakeGame::checkCollision()
{
    for (int i = 0; i < wall.size(); i++)
    {
        if (snake[0].x == wall[i].x && snake[0].y == wall[i].y)
        {
            if (!((snake[0].x == gate_1.x && snake[0].y == gate_1.y) || (snake[0].x == gate_2.x && snake[0].y == gate_2.y)))
            {
                return true;
                break;
            }
        }
    }

    for (int i = 2; i < snake.size(); i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
        {
            return true;
        }
    }

    if (snake.size() < 3) 
    {
        return true;
    }
    if (direction == 'r' && KeyPressed == leftKey) 
    {
        return true;
    }
    if (direction == 'l' && KeyPressed == rightKey)
    {
        return true;
    }
    if (direction == 'u' && KeyPressed == downKey)
    {
        return true;
    }
    if (direction == 'd' && KeyPressed == upKey)
    {
        return true;
    }

    return false;
}


// SnakeGame 실행
void snakeGame::runGame()
{
    isClear = true;
    while (!nextStage())
    {
        if (checkCollision())
        {
            move((maxHeight - 2) / 2, (maxWidth - 20) / 2);
            printw("GAME OVER");
            endwin();
            isClear = false;
            break;
        }
        checkGrowth();
        checkPoison();
        checkGate();
        checkSpeed();
        growthItemTime();
        poisonItemTime();
        speedItemTime();
        gateTime();
        moveSnake();
        if (direction == 'q') 
        {
            break;
        }
        usleep(snakeSpeed); 
    }
    if (isClear)
    {
        move((maxHeight - 2) / 2, (maxWidth - 30) / 2);
        printw("Mission Complete");
        endwin();
}
    }

// 게임 클리어 여부 확인
bool snakeGame::getClear() 
{
    return isClear;
}
