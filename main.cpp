

#include "snakeGame.h"
#include <unistd.h>

int maxheight, maxwidth;
void runGame();
int IsUserReady();
int AskUserToPlayAgain(bool clear);
int AllClear();
void ClearCentre();
int UserInput();

int main()
{
    bool isClear;
    int level = 1;
    if (IsUserReady() == 'y') 
    {
        do
        {
            snakeGame NewSnake(level++);
            NewSnake.runGame();
            isClear = NewSnake.getClear();
            if (!isClear)
            {
                level = 1;
            }
        } while (AskUserToPlayAgain(isClear) == 'y' && level <= 4);

        if (level == 5)
        {
            AllClear();
        }
    }
    return 0;
}

// 화면을 초기화하고 커서를 중간에 위치
void ClearCentre(float x, float y)
{
    clear(); 
    initscr();
    noecho();
    getmaxyx(stdscr, maxheight, maxwidth);
    move((maxheight / y), (maxwidth / x));
}

// 사용자 입력 확인
int UserInput()
{
    int UserInput = getch();
    refresh();
    endwin();
    clear();

    return UserInput;
}

// 시작 메뉴 출력
int IsUserReady()
{
    ClearCentre(3.5, 2.5);
    printw("Welcome to the Snake Game. Are you ready? (y/n)");
    return UserInput();
}

// 게임 완료 혹은 재시도 문장 출력
int AskUserToPlayAgain(bool clear)
{

    if (clear)
    {
        ClearCentre(3.2, 2.5);
        printw("Mission Complete! Do you want to play Continue? (y/n)");
    }
    else
    {
        ClearCentre(2.8, 2.5);
        printw("Do you want to play again? (y/n)");
    }
    return UserInput();
}

// 모두 클리어했을 때 문장 출력
int AllClear()
{
    ClearCentre(3.2, 2.5);
    printw("Congratuation! All Clear!");
    return UserInput();
}