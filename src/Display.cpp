#include "snakeGame.h"
#include <ncurses.h>
// window 그리기
void snakeGame::renderWindow(int level)
{
    int k, q;
    for (int i = 1; i < maxWidth - 12; i++) // 윗벽
    {
        wall.push_back(CharPosition(i, 0));
        start_color();
        init_pair(3, COLOR_WHITE, COLOR_WHITE);
        attron(COLOR_PAIR(3));
        move(0, i);
        addch(edgechar);
        attroff(COLOR_PAIR(3));
        refresh();
    }

    for (int i = 1; i < maxWidth - 12; i++) // 아래 벽
    {
        wall.push_back(CharPosition(i, maxHeight - 1));
        start_color();
        init_pair(3, COLOR_WHITE, COLOR_WHITE);
        attron(COLOR_PAIR(3));
        move(maxHeight - 1, i);
        addch(edgechar);
        attroff(COLOR_PAIR(3));
        refresh();
    }

    for (int i = 1; i < maxHeight - 1; i++) // 왼쪽 벽
    {
        wall.push_back(CharPosition(0, i));
        start_color();
        init_pair(3, COLOR_WHITE, COLOR_WHITE);
        attron(COLOR_PAIR(3));
        move(i, 0);
        addch(edgechar);
        attroff(COLOR_PAIR(3));
        refresh();
    }

    for (int i = 1; i < maxHeight - 1; i++) // 오른쪽 벽
    {
        wall.push_back(CharPosition(maxWidth - 12, i));
        start_color();
        init_pair(3, COLOR_WHITE, COLOR_WHITE);
        attron(COLOR_PAIR(3));
        move(i, maxWidth - 12);
        addch(edgechar);
        attroff(COLOR_PAIR(3));
        refresh();
    }

    int H = (maxHeight - 1) / 5;

    // 레벨에 따라 맵 구성
    switch (level)
    {
    case 1: {// KMU 모양의 장애물
        for (int i = 0; i < (maxWidth - 12) / 10; i++) {
            start_color();
            init_pair(3, COLOR_WHITE, COLOR_WHITE);
            attron(COLOR_PAIR(3));

            wall.push_back(CharPosition((maxWidth - 12) / 10 * 1, H));
            move(H, (maxWidth - 12) / 10 * 1);
            addch(edgechar);

            wall.push_back(CharPosition((maxWidth - 12) / 10 * 2 - i, H));
            move(H, (maxWidth - 12) / 10 * 2 - i);
            addch(edgechar);
            attroff(COLOR_PAIR(3));
            refresh();
            H++;
        }
        for (int i = 0; i < (maxWidth - 12) / 10; i++) {
            start_color();
            init_pair(3, COLOR_WHITE, COLOR_WHITE);
            attron(COLOR_PAIR(3));

            wall.push_back(CharPosition((maxWidth - 12) / 10 * 1, H));
            move(H, (maxWidth - 12) / 10 * 1);
            addch(edgechar);

            wall.push_back(CharPosition((maxWidth - 12) / 10 * 1 + i, H));
            move(H, (maxWidth - 12) / 10 * 1 + i);
            addch(edgechar);
            attroff(COLOR_PAIR(3));
            refresh();
            H++;
        }

    // M
        H = (maxHeight - 1) / 5;
        for (int i = 0; i < (maxWidth - 12) / 10; i++) {
            start_color();
            init_pair(3, COLOR_WHITE, COLOR_WHITE);
            attron(COLOR_PAIR(3));

            wall.push_back(CharPosition((maxWidth - 12) / 10 * 4, H));
            move(H, (maxWidth - 12) / 10 * 4);
            addch(edgechar);

            wall.push_back(CharPosition((maxWidth - 12) / 10 * 6, H));
            move(H, (maxWidth - 12) / 10 * 6);
            addch(edgechar);

            wall.push_back(CharPosition((maxWidth - 12) / 10 * 4 + i, H));
            move(H, (maxWidth - 12) / 10 * 4 + i);
            addch(edgechar);

            wall.push_back(CharPosition((maxWidth - 12) / 10 * 6 - i, H));
            move(H, (maxWidth - 12) / 10 * 6 - i);
            addch(edgechar);

            attroff(COLOR_PAIR(3));
            refresh();
            H++;
        }
        for (int i = 0; i < (maxWidth - 12) / 10; i++) {
            start_color();
            init_pair(3, COLOR_WHITE, COLOR_WHITE);
            attron(COLOR_PAIR(3));

            wall.push_back(CharPosition((maxWidth - 12) / 10 * 4, H));
            move(H, (maxWidth - 12) / 10 * 4);
            addch(edgechar);

            wall.push_back(CharPosition((maxWidth - 12) / 10 * 6, H));
            move(H, (maxWidth - 12) / 10 * 6);
            addch(edgechar);

            attroff(COLOR_PAIR(3));
            refresh();
            H++;
        }

        H = (maxHeight - 1) / 5;
        //U
        for (int i = 0; i < (maxWidth - 12) / 10; i++) {
            start_color();
            init_pair(3, COLOR_WHITE, COLOR_WHITE);
            attron(COLOR_PAIR(3));

            wall.push_back(CharPosition((maxWidth - 12) / 10 * 8, H));
            move(H, (maxWidth - 12) / 10 * 8);
            addch(edgechar);

            wall.push_back(CharPosition((maxWidth - 12) / 10 * 10, H));
            move(H, (maxWidth - 12) / 10 * 10);
            addch(edgechar);

            attroff(COLOR_PAIR(3));
            refresh();
            H++;
        }
        for (int i = 0; i < (maxWidth - 12) / 10; i++) {
            start_color();
            init_pair(3, COLOR_WHITE, COLOR_WHITE);
            attron(COLOR_PAIR(3));

            wall.push_back(CharPosition((maxWidth - 12) / 10 * 8, H));
            move(H, (maxWidth - 12) / 10 * 8);
            addch(edgechar);

            wall.push_back(CharPosition((maxWidth - 12) / 10 * 10, H));
            move(H, (maxWidth - 12) / 10 * 10);
            addch(edgechar);

            if (i == (maxWidth - 12) / 10 - 1) {
                for (int j = 0; j < (maxWidth - 12) / 10 *2 + 1; j++) {
                    wall.push_back(CharPosition((maxWidth - 12) / 10 * 8 + j, H));
                    move(H, (maxWidth - 12) / 10 * 8 + j);
                    addch(edgechar);
                }
            }

            attroff(COLOR_PAIR(3));
            refresh();
            H++;
        }
        break;
    }
    case 2:{//3분할 장애물
        int squareHeight = 4;
        int squareWidth = 4;
        int squareRowStart = (maxHeight - squareHeight) / 2;
        int squareRowEnd = squareRowStart + squareHeight;
        int squareColStart = (maxWidth - squareWidth - 12) / 2;
        int squareColEnd = squareColStart + squareWidth;

        for (int row = 0; row < maxHeight; row++) {
            for (int col = 0; col < maxWidth - 12; col++) {
                if ((col == (maxWidth - 13) / 4 && row >= (maxHeight - 1) / 2 - 2 && row <= (maxHeight - 1) / 2 + 2) ||
                    (col == 3 * (maxWidth - 13) / 4 && row >= (maxHeight - 1) / 2 - 2 && row <= (maxHeight - 1) / 2 + 2))
                    continue;
                if (row == 0 || row == maxHeight - 1 || col == 0 || col == maxWidth - 13 ||
                    col == (maxWidth - 13) / 4 || col == 3 * (maxWidth - 13) / 4 ||
                    ((row >= squareRowStart && row < squareRowEnd) && (col >= squareColStart && col < squareColEnd))) {
                    wall.push_back(CharPosition(col, row));
                    start_color();
                    init_pair(3, COLOR_WHITE, COLOR_WHITE);
                    attron(COLOR_PAIR(3));
                    move(row, col);
                    addch(edgechar);
                    attroff(COLOR_PAIR(3));
                    refresh();
                }
            }
        }
        break;
    }
    case 3: {// X모양의 장애물
        q = 4;
        for (int i = 2; i < maxWidth - 13; i++)
        {
            int cnt = 4;
            while (cnt--) {
                wall.push_back(CharPosition(i, q));
                start_color();
                init_pair(3, COLOR_WHITE, COLOR_WHITE);
                attron(COLOR_PAIR(3));
                move(q, i);
                addch(edgechar);
                attroff(COLOR_PAIR(3));
                refresh();
                i++;

            }
            q++;
        }

        q = 4;
        for (int i = maxWidth - 13; i > 2; i--)
        {
            int cnt = 4;
            while (cnt--) {
                wall.push_back(CharPosition(i, q));
                start_color();
                init_pair(3, COLOR_WHITE, COLOR_WHITE);
                attron(COLOR_PAIR(3));
                move(q, i);
                addch(edgechar);
                attroff(COLOR_PAIR(3));
                refresh();
                i--;

            }
            q++;
        }
        break;

    }
    case 4: //9분할 장애물
        {
        int sixthHeight = (maxHeight - 1) / 6;
        int sixthWidth = (maxWidth - 12) / 6;
        int p1 = sixthHeight;
        int p2 = 3 * sixthHeight;
        int p3 = 5 * sixthHeight;
        int ph1 = sixthWidth;
        int ph2 = 3 * sixthWidth;
        int ph3 = 5 * sixthWidth;

        for (int row = 0; row < maxHeight; row++) {
            for (int col = 0; col < maxWidth - 12; col++) {
                if ((row == 2 * sixthHeight || row == 4 * sixthHeight) && 
                    !(col >= ph1 - 1 && col <= ph1 + 1) && 
                    !(col >= ph2 - 1 && col <= ph2 + 1) &&
                    !(col >= ph3 - 1 && col <= ph3 + 1)
                    || (col == 2 * sixthWidth || col == 4 * sixthWidth) && 
                    !(row >= p1 - 1 && row <= p1 + 1) &&
                    !(row >= p2 - 1 && row <= p2 + 1) &&
                    !(row >= p3 - 1 && row <= p3 + 1)) {
                    wall.push_back(CharPosition(col, row));
                    start_color();
                    init_pair(3, COLOR_WHITE, COLOR_WHITE);
                    attron(COLOR_PAIR(3));
                    move(row, col);
                    addch(edgechar);
                    attroff(COLOR_PAIR(3));
                    refresh();
                }
            }
        }

        }
    break;
    }

    // 모서리 부분을 다른 색으로 표시
    start_color();
    init_pair(4, COLOR_BLACK, COLOR_BLACK);
    attron(COLOR_PAIR(4));
    move(0, 0);
    addch(edgechar);
    move(0, maxWidth - 12);
    addch(edgechar);
    move(maxHeight - 1, 0);
    addch(edgechar);
    move(maxHeight - 1, maxWidth - 12);
    addch(edgechar);
    attroff(COLOR_PAIR(4));
    refresh();
}

// 뱀의 body
void snakeGame::renderSnake()
{
    for (int i = 0; i < 3; i++)
    {
        snake.push_back(CharPosition(7 - i, 1));
    }

    for (int i = 0; i < snake.size(); i++)
    {
        move(snake[i].y, snake[i].x);
        addch(snakeShape);
    }
    return;
}


// 점수 출력
void snakeGame::displayScore()
{   
    //Score Board
    move(0, maxWidth - 11);
    printw("Score Board");

    move(1, maxWidth - 9);
    printw("B : (%d)", currentLength);

    move(2, maxWidth - 9);
    printw("+ : (%d)", scoreGrowthItem);

    move(3, maxWidth - 9);
    printw("- : (%d)", scorePoisonItem);

    move(4, maxWidth - 9);
    printw("* : (%d)", scoreSpeedItem);

    move(5, maxWidth - 9);
    printw("G : (%d)", scoreGate);

    //Mission
    move(7, maxWidth - 11);
    printw("Mission");

    move(8, maxWidth - 9);
    if (requiredLength - currentLength <= 0)
    {
        printw("B : (%s)", "v");
    }
    else
    {
        printw("B : (%d)", requiredLength - currentLength);
    }

    move(9, maxWidth - 9);
    if (requiredGrowthItem - scoreGrowthItem <= 0)
    {
        printw("+ : (%s)", "v");
    }
    else
    {
        printw("+ : (%d)", requiredGrowthItem - scoreGrowthItem);
    }

    move(10, maxWidth - 9);
    if (requiredPoisonItem - scorePoisonItem <= 0)
    {
        printw("- : (%s)", "v");
    }
    else
    {
        printw("- : (%d)", requiredPoisonItem - scorePoisonItem);
    }

    move(11, maxWidth - 9);
    if (requiredSpeedItem - scoreSpeedItem <= 0)
    {
        printw("* : (%s)", "v");
    }
    else
    {
        printw("* : (%d)", requiredSpeedItem - scoreSpeedItem);
    }

    move(12, maxWidth - 9);
    if (requiredGate - scoreGate <= 0)
    {
        printw("G : (%s)", "v");
    }
    else
    {
        printw("G : (%d)", requiredGate - scoreGate);
    }

    // 뱀 그래픽
    for (int i = 1; i < 8; i++) {
        start_color();
        init_pair(3, COLOR_WHITE, COLOR_WHITE);
        attron(COLOR_PAIR(3));
        move(14, maxWidth - 9 + i);
        addch(edgechar);
        attroff(COLOR_PAIR(3));

    }

    for (int i = 1; i < 8; i++) {
        attron(COLOR_PAIR(3));
        move(18, maxWidth - 9 + i);
        addch(edgechar);
        attroff(COLOR_PAIR(3));

    }

    for (int i = 1; i < 5; i++) {
        attron(COLOR_PAIR(3));
        move(14 + i, maxWidth - 9);
        addch(edgechar);
        attroff(COLOR_PAIR(3));

    }

    for (int i = 1; i < 5; i++) {
        attron(COLOR_PAIR(3));
        move(14 + i, maxWidth - 1);
        addch(edgechar);
        attroff(COLOR_PAIR(3));

    }

    //뱀 혀
    attron(COLOR_PAIR(3));
    move(19, maxWidth - 6);
    addch(edgechar);
    attroff(COLOR_PAIR(3));

    attron(COLOR_PAIR(3));
    move(20, maxWidth - 7);
    addch(edgechar);
    attroff(COLOR_PAIR(3));

    //뱀 눈
    attron(COLOR_PAIR(3));
    move(16, maxWidth - 7);
    addch(edgechar);
    attroff(COLOR_PAIR(3));

    attron(COLOR_PAIR(3));
    move(16, maxWidth - 5);
    addch(edgechar);
    attroff(COLOR_PAIR(3));



}
