#include "snakeGame.h"

//snakeGame
snakeGame::snakeGame(int level)
{
    if (level == 1)
        getKey();

    //shape
    snakeShape = 'x';
    edgechar = 'o'; 
    growthItemShape = '+';
    poisionItemShape = '-';
    speedItemShape = '*';

    growthItem.x = 0;
    growthItem.y = 0;
    poisonItem.x = 0;
    poisonItem.y = 0;
    speedItem.x = 0;
    speedItem.y = 0;
    currentLength = 3;
    isClear = false;

    requiredLength = level + 3; // 다음 단계로 넘어가기 위해 만족해야 할 뱀의 길이
    requiredGrowthItem = level; // 다음 단계로 넘어가기 위해 만족해야 할 Growth Item 먹은 수
    requiredPoisonItem = level; // 다음 단계로 넘어가기 위해 만족해야 할 Poison Item 먹은 수
    requiredGate = level;       // 다음 단계로 넘어가기 위해 만족해야 할 Gate 통과 횟수
    requiredSpeedItem = level;  // 다음 단계로 넘어가기 위해 만족해야 할 Speed Item 먹은 수

    scoreGrowthItem = 0;
    scorePoisonItem = 0;
    scoreGate = 0;
    scoreSpeedItem = 0;
    snakeSpeed = 90000;
    maxItemTime = 120; // 뱀이 아무것도 먹지 않을 때 아이템 위치가 대기하는 시간
    maxGateTime = 120;
    eatGrowthItem = 0;
    eatPoisionItem = 0;
    atGate1 = 0;
    atGate2 = 0;
    direction = 'r';
    growthItemTimer = 0;
    poisonItemTimer = 0;
    speedItemTimer = 0;
    gateTimer = 0;
    srand(time(NULL));

    setWindow(level);
    renderWindow(level);
    placeGrowthItem();
    placePoisonItem();
    placeSpeedItem();
    placeGate();
    renderSnake();
    displayScore();
    refresh();
}

snakeGame::~snakeGame()
{
    nodelay(stdscr, false);
    getch();
    endwin();
}

// window 초기화
void snakeGame::setWindow(int level)
{
    initscr(); // initialise the screen
    nodelay(stdscr, TRUE);
    keypad(stdscr, true);                  
    noecho(); // user input is not displayed on the screen
    curs_set(0); // cursor symbol is not not displayed on the screen
    getmaxyx(stdscr, maxHeight, maxWidth); // define dimensions of game window
    maxHeight -= (level - 1) * 3;
    maxWidth -= (level - 1) * 6;
    return;
}

// 방향키 입력 받기
void snakeGame::getKey()
{
    initscr();
    cbreak();
    noecho();

    keypad(stdscr, TRUE);

    getmaxyx(stdscr, maxHeight, maxWidth);
    move((maxHeight / 2.5), (maxWidth / 3.5));
    printw("Press right key : ");
    rightKey = getch();
    refresh();
    clear();

    getmaxyx(stdscr, maxHeight, maxWidth);
    move((maxHeight / 2.5), (maxWidth / 3.5));
    printw("Press left key : ");
    leftKey = getch();
    refresh();
    clear();

    getmaxyx(stdscr, maxHeight, maxWidth);
    move((maxHeight / 2.5), (maxWidth / 3.5));
    printw("Press up key : ");
    upKey = getch();
    refresh();
    clear();

    getmaxyx(stdscr, maxHeight, maxWidth);
    move((maxHeight / 2.5), (maxWidth / 3.5));
    printw("Press down key : ");
    downKey = getch();
    refresh();

    endwin();
    clear();
}
