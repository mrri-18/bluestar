#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#pragma once
#include "Positions.h"

#define WIDTH 30        //가로
#define HEIGHT 40        //세로
#define TRUE 1
#define FALSE 0

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80 
#define MAX_SIZE 40//행
#define MAX_SIZE1 40 //열
#define XPOS 50
#define YPOS 5

Enemy enemy[WIDTH];
Player player;
void finish();
void brandpicture();
void init();    // 초기값
void FallEnemy();   // 적의 움직임 
int DamagedPlayer();    // 플레이어가 적에게 닿을 경우 (패배) 
int isKeyDown(int key);     // 키 다운 처리 
void MovePlayer();      // 플레이어 이동 (좌/우) 
void PrintGame();     // 게임 화면 출력
void finish();      // 열쇠에 닿을경우 해당 스테이지 클리어 및 다음스테이지 갈지에 대한 여부 화면 출력
void twostage();    // 2 스테이지로 이동
void brandpicture();    // 방탈출 로고
void startpicture();
void titleDraw();
void menuDraw();
void sung();

void GotoXY(int x, int y);
void print_mazeGame(char maze[][MAX_SIZE], int row);
int is_block(char maze[][MAX_SIZE], int row, int col);
void move_maze(char maze[][MAX_SIZE], int* row, int* col);
void CursorView(char show);
void complete_exit();
void complete_exit2();

int i;
void brandpicture()
{
    printf(" \n \n \n \n");
    printf("                  ■■■■     ■■■      ■■■       ■       ■■■■     ■■■■\n");
    printf("                  ■          ■          ■          ■  ■     ■     ■    ■\n");
    printf("                  ■■■■     ■■■■   ■         ■■■■    ■■■■     ■■■■\n");
    printf("                  ■                  ■  ■         ■    ■    ■           ■\n");
    printf("                  ■■■■     ■■■■    ■■■    ■    ■    ■           ■■■■\n");
    printf("\n");
    printf("                         ■■■        ■■■      ■■■       ■■    ■■\n");
    printf("                         ■   ■      ■     ■   ■     ■     ■ ■  ■ ■\n");
    printf("                         ■■■       ■     ■   ■     ■     ■   ■   ■\n");
    printf("                         ■   ■      ■     ■   ■     ■     ■        ■\n");
    printf("                         ■    ■      ■■■      ■■■       ■        ■\n");
}
void startpicture()
{
    brandpicture();
    for (int i = 0; i < 5; i++) {
        system("color 09");
        Sleep(180);
        system("color 06");
    }
    printf("\n\n\n");
    printf("                          ┌──────────────────────────────────────────────┐\n");

    printf("                          │                                              │\n");

    printf("                          │                 < 방탈출 게임 >              │\n");
    printf("                          │                                              │\n");
    printf("                          │               열쇠에 접근하세요!             │\n");
    printf("                          │                                              │\n");
    printf("                          │                 자동으로 시작!               │\n");
    printf("                          │                                              │\n");
    printf("                          │      게임 조작키 : 방향키 ←, ↑, ↓, →     │\n");
    printf("                          │                                              │\n");
    printf("                          ├──────────────────────────────────────────────┤\n");
    printf("                          │                                              │\n");
    printf("                          │                                              │\n");
    printf("                          │                              ▩▩            │\n");
    printf("                          │                ♥==          ▩              │\n");
    printf("                          │                              ▩▩            │\n");
    printf("                          │        ♥==                  ▩              │\n");
    printf("                          │           ○        ♥==     ▩▩▩          │\n");
    printf("                          │          ┌□┘                ▩  ▩          │\n");
    printf("                          │      ...  ll      ♥==       ▩▩▩          │ \n");
    printf("                          │                                              │\n");
    printf("                          │                                              │\n");
    printf("                          └──────────────────────────────────────────────┘\n");
    Sleep(1000);

}
//// 초기값 ////
void init()
{
    for (i = 0; i < WIDTH; i++)
        enemy[i].con = FALSE;
    //플레이어 위치는 중앙
    player.x = WIDTH / 2;
    player.y = HEIGHT; //개입
}
void init2()
{
    for (i = 0; i < WIDTH; i++)
        enemy[i].con = FALSE;
    //플레이어 위치는 중앙
    player.x = 6;
    player.y = 37;
}

//// 피할 적들 처리 ////
/* 적 생성 */

void CreateEnemy(int a, int b, int c, int count)
{
    for (i = 0; i < count; i++)
    {
        //해당 인덱스[i]에 적이 없으면 (FALSE 이면 실행)
        if (!enemy[i].con)
        {
            //가로 (x축) 무작위로 적 출현, 세로(y축)은 출현 위치 항상 일치
            enemy[i].x = rand() % (b + 1 - a) + a;     //a~b까지 랜덤한 값을 계산
            enemy[i].y = c - 1; // c= height
            //적이 출현한 인덱스 [i]의 상태 = TRUE로 변경
            enemy[i].con = TRUE;
            return;
        }
    }
}
/* 적의 움직임 */
void FallEnemy()
{
    for (i = 0; i < 15; i++)
    {
        //해당 인덱스 [i]에 적이 있으면 (TRUE라면) 움직임 실행
        if (enemy[i].con)
        {

            enemy[i].y--;
            gotoxy(enemy[i].x, HEIGHT - enemy[i].y);
            printf("♥");
            gotoxy(enemy[i].x, HEIGHT - enemy[i].y - 1);
            printf("  ");

        }
    }
}
/* 피하기 성공한 적(바닥에 떨어진 적) 삭제 */

void DelEnemy(int h) {
    int i;
    for (i = 0; i < WIDTH; i++)
    {
        if (enemy[i].con && enemy[i].y < h)
            enemy[i].con = FALSE;
    }
}
/* 플레이어가 적에게 닿을 경우 (패배) 또는 열쇠에 닿을 경우 다음스테이지 통과 */
int DamagedPlayer()
{
    int i;
    for (i = 0; i < WIDTH; i++)
    {
        //적의 상태가 TRUE && 적의 위치가 y=0 즉 바닥 && 적의 x축 위치 = 플레이어의 x축 위치
        if (enemy[i].x == player.x)
        {
            // 같은 행인지 확인
            if (HEIGHT - enemy[i].y == player.y) {
                return TRUE;
                //complete_exit(1);
            }
        }
        else if (player.x == WIDTH / 2 - 1 && player.y == HEIGHT / 2 - 9)
        {
            finish();
        }
        else if (player.x == WIDTH / 2 && player.y == HEIGHT / 2 + 1 - 8)
        {
            finish();
        }
        else if (player.x == WIDTH / 2 - 1 && player.y == HEIGHT / 2 - 8)
        {
            finish();
        }
        else if (player.x == WIDTH / 2 - 1 && player.y == HEIGHT / 2 - 7)
        {
            finish();
        }
        else if (player.x == WIDTH / 2 + 1 && player.y == HEIGHT / 2 - 7)
        {
            finish();
        }
        else if (player.x == WIDTH / 2 + 1 && player.y == HEIGHT / 2 - 6)
        {
            finish();
        }
        else if (player.x == WIDTH / 2 + 1 && player.y == HEIGHT / 2 - 5)
        {
            finish();
        }
        else if (player.x == WIDTH / 2 + 1 && player.y == HEIGHT / 2 - 4)
        {
            finish();
        }
        else if (player.x == WIDTH / 2 && player.y == HEIGHT / 2 - 4)
        {
            finish();
        }
        else if (player.x == WIDTH / 2 + 1 && player.y == HEIGHT / 2 - 3)
        {
            finish();
        }
        else if (player.x == WIDTH / 2 + 1 && player.y == HEIGHT / 2 - 2)
        {
            finish();
        }
        else if (player.x == WIDTH / 2 && player.y == HEIGHT / 2 - 2)
        {
            finish();
        }
    }
    //닿지 않았으면 FALSE 반환
    return FALSE;
}

//// 플레이어 처리 ////
/* 키 다운 처리 */
int isKeyDown(int key)
{
    //***GetAsyncKey는 키가 눌렸다면 최상위 비트를 1로 설정, 이전에 키가 눌렸다면 최하위 비트를 1로 설정
    //0x8000은 최상위 비트 -> 16진수는 2비트가 4개 모인 비트 -> 0x8000 = 1000 0000 0000 0000를 의미
    // 즉 최하위 비트는 0x0001 -> 0000 0000 0000 0001
    // 따라서 (GetAsyncKeyState(key) & 0x8000) != 0 은 현재 키가 눌려있다면 참(TRUE)
    return ((GetAsyncKeyState(key) & 0x8000) != 0);
}

/* 플레이어 이동 (좌/우) */
void MovePlayer()
{
    gotoxy(player.x, player.y);
    printf("□");
    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        player.y--;
        gotoxy(player.x, player.y + 1);
        printf("  ");
    };
    if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        player.y++;
        gotoxy(player.x, player.y - 1);
        printf("  ");
    };
    if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        player.x--;
        gotoxy(player.x + 1, player.y);
        printf("  ");
    };
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        player.x++;
        gotoxy(player.x - 1, player.y);
        printf("  ");
    };

    //위치 범위 제한
    if (player.x < 0)
        player.x = 0;
    if (player.x > WIDTH - 1)
        player.x = WIDTH - 1;
    if (player.y > HEIGHT + 1)
        player.y = HEIGHT;
    if (player.y < 0)
        player.y = 0;


}

//// 게임 화면 출력 ////
void PrintGame()
{
    //모든 화면 clear

    //플레이어 출력
    //for (int i = 0; i < WIDTH; i++)
    //{
    //    if (enemy[i].con)
    //    {
    //        //적 위치에 적군 출력
    //        gotoxy(enemy[i].x, HEIGHT - enemy[i].y);
    //        printf("♥");
    //    }
    //}
    gotoxy(0, HEIGHT + 1);
    for (i = 0; i < WIDTH; i++)
        printf("▩");
    gotoxy(0, 0);
    for (i = 0; i < WIDTH; i++)
        printf("▩");
    gotoxy(0, 0);
    for (i = 0; i < HEIGHT + 1; i++)
    {
        printf("▩\n");
    }

    for (i = 0; i < HEIGHT + 2; i++)
    {
        gotoxy(WIDTH, i);
        printf("▩\n");
    }


    gotoxy(WIDTH / 2, HEIGHT / 2 - 9);
    printf("▩");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 - 9);
    printf("▩");
    gotoxy(WIDTH / 2 - 1, HEIGHT / 2 - 9);
    printf("▩");
    gotoxy(WIDTH / 2, HEIGHT / 2 + 1 - 8);
    printf("▩");
    gotoxy(WIDTH / 2 - 1, HEIGHT / 2 - 8);
    printf("▩");
    gotoxy(WIDTH / 2 - 1, HEIGHT / 2 + 1 - 8);
    printf("▩");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 - 8);
    printf("▩");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 + 1 - 8);
    printf("▩");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 + 2 - 8);
    printf("▩");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 + 3 - 8);
    printf("▩");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 + 4 - 8);
    printf("▩");
    gotoxy(WIDTH / 2, HEIGHT / 2 + 4 - 8);
    printf("▩");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 + 5 - 8);
    printf("▩");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 + 6 - 8);
    printf("▩");
    gotoxy(WIDTH / 2, HEIGHT / 2 + 6 - 8);
    printf("▩");

    gotoxy(WIDTH + 10, HEIGHT / 2 - 11);
    printf("방탈출 1STAGE");
    gotoxy(WIDTH + 9, HEIGHT / 2 - 10);
    printf("=================");
    gotoxy(WIDTH + 9, HEIGHT / 2 - 12);
    printf("=================");
    gotoxy(WIDTH + 9, HEIGHT / 2 - 10);
    printf("=");
    gotoxy(WIDTH + 9, HEIGHT / 2 - 11);
    printf("=");
    gotoxy(WIDTH + 9, HEIGHT / 2 - 12);
    printf("=");
    gotoxy(WIDTH + 17, HEIGHT / 2 - 11);
    printf("=");
    gotoxy(WIDTH + 5, HEIGHT / 2 - 9);
    printf("= = = = = = = = = = = = = = = = = ");
    for (i = 0; i < 13; i++)
    {
        gotoxy(WIDTH + 5, HEIGHT / 2 - 8 + i);
        printf("=");
    }
    gotoxy(WIDTH + 5 + 1, HEIGHT / 2 + 9);
    printf("- - - - - - - - - - - - - - - - ");
    gotoxy(WIDTH + 5, HEIGHT / 2 - 9 + 12);
    printf("= = = = = = = = = = = = = = = = =");
    for (i = 0; i < 13; i++)
    {
        gotoxy(WIDTH + 22, HEIGHT / 2 - 9 + i);
        printf("=");
    }
    gotoxy(WIDTH + 7, HEIGHT / 2 - 9 + 2);
    printf("       < 탈출 방법 > ");
    gotoxy(WIDTH + 7, HEIGHT / 2 - 9 + 4);
    printf(" 위에서 떨어지는 장애물을 ");
    gotoxy(WIDTH + 7, HEIGHT / 2 - 9 + 5);
    printf("피해서 방을 탈출할 수 있는");
    gotoxy(WIDTH + 7, HEIGHT / 2 - 9 + 6);
    printf("      열쇠를 먹어라!");
    gotoxy(WIDTH + 7, HEIGHT / 2 - 9 + 9);
    printf("중앙에 있는 열쇠에 도달하면");
    gotoxy(WIDTH + 7, HEIGHT / 2 - 9 + 10);
    printf("  열쇠를 먹을 수 있습니다");
    gotoxy(WIDTH + 5, HEIGHT / 2 - 9 + 13);
    printf("- - - - - - - - - - - - - - - - - -");
    gotoxy(WIDTH + 7, HEIGHT / 2 - 9 + 15);
    printf("          < 주의 >");
    gotoxy(WIDTH + 7, HEIGHT / 2 - 9 + 16);
    printf("   목숨은 단 '한'번입니다");
    for (i = 0; i < 5; i++)
    {
        gotoxy(WIDTH + 5, HEIGHT / 2 + 5 + i);
        printf("-");
    }
    for (i = 0; i < 5; i++)
    {
        gotoxy(WIDTH + 22, HEIGHT / 2 + 5 + i);
        printf("-");
    }
}

void finish()
{
    system("cls");
    int next;
    printf("\n");
    printf("\n");
    printf("\n");
    brandpicture();
    printf("\n\n\n");
    printf("                ========================================================================");
    gotoxy(WIDTH / 2 - 6, HEIGHT / 2 + 3);
    printf("1 STAGE 방탈출에 성공하셨습니다. 다음 2STAGE 방탈출로 넘어가겠습니까?");
    gotoxy(WIDTH / 2 + 7, HEIGHT / 2 + 6);
    printf("[ YES(y) / NO(n) ]");
    gotoxy(WIDTH / 2 + 6, HEIGHT / 2 + 7);
    printf("(y 또는 n을 눌러주세요)\n");
    gotoxy(WIDTH / 2 - 7, HEIGHT / 2 + 9);
    printf("========================================================================");
    for (int i = 0; i < 9; i++)
    {
        gotoxy(WIDTH / 2 - 7, HEIGHT / 2 + 9 - i);
        printf("=");
    }
    for (int i = 0; i < 9; i++)
    {
        gotoxy(WIDTH / 2 - 7 + 36, HEIGHT / 2 + 9 - i);
        printf("=");
    }
    next = getchar();
    if (next == 'y')
    {
        twostage();
    }
    if (next == 'n') {
        complete_exit(1);
    }
}

char maze[MAX_SIZE][MAX_SIZE1] = {
    {'1','1','1','1','1','1','1','1','1','1','1', '1', '1', '1', '1', '1', '1', '1', '1', '1','1', '1', '1', '1', '1', '1', '1', '1', '1', '1','1','1','1','1', '1', '1', '1', '1', '1', '1'},
    {'1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','y','0','0','0','0','0','2','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','0','0','1','1','1','1','0','0','0','0','1','1','1','1','1','0','0','0','1','1','1','1','1','1','1','1','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','1'},
    {'1','0','0','0','1','1','1','1','0','0','0','1','0','0','0','0','1','1','1','1','0','0','0','1','0','0','0','1','0','0','0','1','1','1','1','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','1','1','1','1','1','1','1','1','1','1','1','0','0','0','0','1','1','1','1','1','0','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1'},
    {'1','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1'},
    {'1','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1'},
    {'1','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1'},
    {'1','1','1','1','1','0','0','0','1','1','1','1','0','0','0','1','1','1','1','1','0','0','0','1','0','0','0','1','1','1','1','1','0','0','0','1','0','0','0','1'},
    {'1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','1'},
    {'1','0','0','0','1','0','0','0','0','0','y','2','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','1'},
    {'1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','1','1','1','1','1','1','1','1','0','0','0','1','0','0','0','1','1','1','1','1','1','1','1','1','0','0','0','1','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','1','1','1','1','1','1','1','1','0','0','0','1','1','1','1','1','0','0','0','1','1','1','1','0','0','0','0','1','0','0','0','1','0','0','0','1'},
    {'1','0','0','0','1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','1'},
    {'1','0','0','0','1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','1'},
    {'1','0','0','0','1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','1','1','1','1','1','1','1','1'},
    {'1','0','0','0','1','1','1','1','0','0','0','1','1','1','1','1','0','0','0','1','1','1','1','1','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','1','1','1','1','0','0','0','1','0','0','0','1','1','1','1','1','0','0','0','1','1','1','1','1','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','1','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','1','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','1','1','1','1'},
    {'1','0','0','0','1','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','y','2','1','0','0','0','0','0','0','1','1','1','1','1','0','0','0','1','1','1','1','1','0','0','0','1','1','1','1','1','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1'},
    {'1','1','1','1','1','1','1','1','1','1','1', '1', '1', '1', '1', '1', '1', '1', '1', '1','1', '1', '1', '1', '1', '1', '1', '1', '1', '1','1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}

};



void twostage()
{
    system("cls");
    printf("두번째 스테이지 시작");
    titleDraw();
    menuDraw();
    system("cls");
    init2();
    system("mode con cols=170 lines=50 | title 방'탈'출 '모'음 ");

    int row = 1, col = 0; //시작 위치 초기화

    CursorView(0);

    GotoXY(XPOS - 3, YPOS - 2);
    printf("  2 STAGE : 열쇠 찾기 찾기 게임");
    sung();
    while (1) //게임 start
    {
        print_mazeGame(maze, 40);
        move_maze(maze, &row, &col);
    }
}

void sung()
{
    gotoxy(5, 15);
    printf("        방탈출 2 STAGE\n");
    printf("  = = = = = = = = = = = = = = = = = = = = = = = =\n");
    printf("  =              KEY ESCAPE ROOM                =\n");
    printf("  =                                             =\n");
    printf("  =             <룰은 간단합니다!>              =\n");
    printf("  =                                             =\n");
    printf("  =          모든 열쇠를 다 먹으세요.           =\n");
    printf("  =             열쇠를 다 먹으면                =\n");
    printf("  =   이 방에서 최종적으로 탈출할수 있습니다.   =\n");
    printf("  =                                             =\n");
    printf("  =                                             =\n");
    printf("  =              KEY SHAPE :  0┬┐               =\n");
    printf("  =                                             =\n");
    printf("  =             PLAYER SHAPE : ●               =\n");
    printf("  =                                             =\n");
    printf("  =                BARRIER : ■                 =\n");
    printf("  =                                             =\n");
    printf("  =                                             =\n");
    printf("  = = = = = = = = = = = = = = = = = = = = = = = =\n ");
}

void CursorView(char show) //커서를 없애는 함수
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void GotoXY(int x, int y) //콘솔 위에 커서 위치를 바꾸어 원하는 곳에 미로를 출력하기 위한 함수
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKey() //키를 받아들이는 함수
{
    if (_kbhit() != 0) //키 입력이 유효할 경우
    {
        return _getch(); //입력한 키 반환
    }

    return 0; //그렇지 않을 경우 0반환
}

void print_mazeGame(char maze[][MAX_SIZE], int row) //미로 frame(틀)을 그려주는 함수
{

    for (int i = 0; i < row; i++)
    {
        GotoXY(XPOS, YPOS + i);
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (maze[i][j] == '1')
                printf("■");
            else if (maze[i][j] == 'y')
                printf("0┬┐");
            else if (maze[i][j] == '0')
                printf("  ");
            else if (maze[i][j] == '2')
                printf(" ");
            else
                printf("●");
        }
        puts("");
    }
}

int is_block(char maze[][MAX_SIZE], int i, int j)
{

    if (maze[i][j] == '1' || maze[i][j] == 'y') //미로가 벽일 경우, 종점일 경우
        return 1;
    else
        return 0;
}

int is_finish(char maze[][MAX_SIZE], int i, int j)
{

    if (maze[i][j] == 'y') //종점일 경우
        return 1;
    else
        return 0;
}

void complete_exit(int num) //완료한 후 프로그램을 종료시키는 함수
{
    system("mode con cols=130 lines=30 | title 방'탈'출 '모'음 ");
    /*static cout;
    cout++;
    if (cout == 3)*/
    {
        system("cls");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("                                            ■■■■    ■■      ■        ■  ");
        printf("                                                                                              ■         ■  ■     ■        ■    \n");
        printf("                                             ■■■■  ■■■■    ■        ■           \n");
        printf("                                             ■       ■      ■   ■        ■ \n");
        printf("                                             ■       ■      ■   ■■■■  ■■■■          \n");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("                                        ┌──────────────────────────────────────────────┐\n");

        printf("                                         │                                              │\n");
        printf("                                         │                                              │\n");
        printf("                                         │         %d단계에서 게임이 종료되었습니다.     │\n", num);
        printf("                                         │                                              │\n");

        printf("                                         │                                              │\n");
        printf("                                         └──────────────────────────────────────────────┘\n");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        exit(0);
    }
}

void complete_exit2() //완료한 후 프로그램을 종료시키는 함수
{
    static cout;
    cout++;
    if (cout == 3)
    {
        system("cls");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("                   ■■■■   ■■■■    ■ ■  ■ ■    ■■■   ■        ■■■■  ■■■■■   ■■■■       \n");
        printf("                   ■         ■      ■   ■   ■   ■    ■   ■  ■        ■            ■       ■              \n");
        printf("                   ■         ■      ■   ■        ■    ■■■   ■        ■■■■      ■       ■■■■    \n");
        printf("                   ■         ■      ■   ■        ■    ■       ■        ■            ■       ■         \n");
        printf("                    ■■■■   ■■■■    ■        ■    ■       ■■■■  ■■■■      ■       ■■■■       \n");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("                                        ┌──────────────────────────────────────────────┐\n");

        printf("                                         │                                              │\n");
        printf("                                         │                                              │\n");
        printf("                                         │         2단계에서 게임이 종료되었습니다.     │\n");
        printf("                                         │                                              │\n");
        printf("                                         │         최종적으로 방을 탈출하셨습니다       │\n");

        printf("                                         │                                              │\n");
        printf("                                         └──────────────────────────────────────────────┘\n");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        exit(0);
    }
}

void move_maze(char maze[][MAX_SIZE], int* row, int* col) //객체(게임 주인공?)을 움직이는 함수
{
    int chr; //키를 받아들이기 위한 변수
    int i = *row; //1
    int j = *col; //0


    chr = GetKey();

    if (chr == 0 || chr == 0xe0) 
    {
        chr = GetKey();
        switch (chr)
        {
        case UP:
            i--;
            if (!(is_block(maze, i, j))) //블럭이 아닐 경우 객체를 옮길 수 있음
            {
                maze[*row][j] = '0'; //이전 블록에 0을 삽입 
                maze[i][j] = 'x'; //방향키를 옮긴 뒤 x를 삽입
                *row -= 1;
            }
            else if (is_finish(maze, i, j)) //종점일 경우
            {
                maze[*row][j] = '0';
                maze[i][j] = 'x';
                print_mazeGame(maze, 12 + 5);
                complete_exit2();
            }
            break;

        case DOWN:
            i++;
            if (!(is_block(maze, i, j)))
            {
                maze[*row][j] = '0';
                maze[i][j] = 'x';
                *row += 1;
            }
            else if (is_finish(maze, i, j)) //종점일 경우
            {
                maze[*row][j] = '0';
                maze[i][j] = 'x';
                print_mazeGame(maze, 12 + 5);
                complete_exit2();
            }
            break;

        case LEFT:
            j--;
            if (!(is_block(maze, i, j)))
            {
                maze[i][*col] = '0';
                maze[i][j] = 'x';
                *col -= 1;
            }
            else if (is_finish(maze, i, j)) //종점일 경우
            {
                maze[*row][j] = '0';
                maze[i][j] = 'x';
                print_mazeGame(maze, 12 + 5);
                complete_exit2();
            }
            break;

        case RIGHT:
            j++;
            if (!(is_block(maze, i, j)))
            {
                maze[i][*col] = '0';
                maze[i][j] = 'x';
                *col += 1;
            }
            else if (is_finish(maze, i, j)) //종점일 경우
            {
                maze[*row][j] = '0';
                maze[i][j] = 'x';
                print_mazeGame(maze, 12 + 5);
                complete_exit2();
            }
            break;
        }
    }

}

void titleDraw() {
    int i;
    //문 출력
    gotoxy(0, HEIGHT + 1);
    for (i = 0; i < WIDTH + 2; i++)
        printf("■");
    gotoxy(0, 0);
    for (i = 0; i < WIDTH + 2; i++)
        printf("■");
    gotoxy(0, 0);
    for (i = 0; i < HEIGHT + 1; i++)
        printf("■\n");
    for (i = 0; i < HEIGHT + 1; i++) {
        gotoxy(WIDTH + 1, i + 1);
        printf("■\n");
    }
    gotoxy(25, HEIGHT / 2);
    printf("■■■\n");
    gotoxy(25, HEIGHT / 2 - 1);
    printf("■■■\n");
    gotoxy(25, HEIGHT / 2 - 2);
    printf("■■■\n");
}

void menuDraw() {
    for (i = 0; i < 3; i++) {
        gotoxy(25, 20 - i);
        printf("■■■\n");
    }
    Sleep(500);
    printf("\n");
    gotoxy(10, 10);
    printf("                                          ■           !KNOCK KNOCK!\n");
    Sleep(500);
    printf("■                                                            ■                   !kNOCK KNOOK!\n");
    Sleep(500);
    printf("■                                                            ■                           !KNOCK KNOCK!\n");
    Sleep(500);
    gotoxy(4, 30);
    printf("┌─-───────────────────────────────────────────┐\n");
    printf("■      │                                             │\n");
    printf("■      │                                             │\n");
    printf("■      │             방에 들어가시겠습니까?          │\n");
    //gotoxy(WIDTH / 2 - 10, 12);
    printf("■      │                                             │\n");
    //gotoxy(WIDTH / 2 - 10, 13);
    printf("■      │                                             │\n");

    //gotoxy(WIDTH / 2 - 10, 14);
    printf("■      └───-─────────────────────────────────────────┘");
    printf("\n");
    Sleep(1000);

}

//// main 함수 ////
void main(void)
{

    system("mode con cols=110 lines=50 | title 방'탈'출 '모'임 ");
    startpicture();
    system("cls");
    init();


    do {
        //매번 실행할 때마다 다른 값을 주기 위한 시드값 설정
        srand((int)malloc(NULL));
        CreateEnemy(3, 29, 41, WIDTH);
        DelEnemy(0);
        FallEnemy();
        PrintGame();
        MovePlayer();
        CursorView(0);
        Sleep(100);

        //게임의 속도 조절을 위해 Sleep 설정

    } while (DamagedPlayer() == 0);    //닿지 않으면 반복
    complete_exit(1);
}
