#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#pragma once
#include "Positions.h"

#define WIDTH 30        //����
#define HEIGHT 40        //����
#define TRUE 1
#define FALSE 0

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80 
#define MAX_SIZE 40//��
#define MAX_SIZE1 40 //��
#define XPOS 50
#define YPOS 5

Enemy enemy[WIDTH];
Player player;
void finish();
void brandpicture();
void init();    // �ʱⰪ
void FallEnemy();   // ���� ������ 
int DamagedPlayer();    // �÷��̾ ������ ���� ��� (�й�) 
int isKeyDown(int key);     // Ű �ٿ� ó�� 
void MovePlayer();      // �÷��̾� �̵� (��/��) 
void PrintGame();     // ���� ȭ�� ���
void finish();      // ���迡 ������� �ش� �������� Ŭ���� �� ������������ ������ ���� ���� ȭ�� ���
void twostage();    // 2 ���������� �̵�
void brandpicture();    // ��Ż�� �ΰ�
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
    printf("                  �����     ����      ����       ��       �����     �����\n");
    printf("                  ��          ��          ��          ��  ��     ��     ��    ��\n");
    printf("                  �����     �����   ��         �����    �����     �����\n");
    printf("                  ��                  ��  ��         ��    ��    ��           ��\n");
    printf("                  �����     �����    ����    ��    ��    ��           �����\n");
    printf("\n");
    printf("                         ����        ����      ����       ���    ���\n");
    printf("                         ��   ��      ��     ��   ��     ��     �� ��  �� ��\n");
    printf("                         ����       ��     ��   ��     ��     ��   ��   ��\n");
    printf("                         ��   ��      ��     ��   ��     ��     ��        ��\n");
    printf("                         ��    ��      ����      ����       ��        ��\n");
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
    printf("                          ������������������������������������������������������������������������������������������������\n");

    printf("                          ��                                              ��\n");

    printf("                          ��                 < ��Ż�� ���� >              ��\n");
    printf("                          ��                                              ��\n");
    printf("                          ��               ���迡 �����ϼ���!             ��\n");
    printf("                          ��                                              ��\n");
    printf("                          ��                 �ڵ����� ����!               ��\n");
    printf("                          ��                                              ��\n");
    printf("                          ��      ���� ����Ű : ����Ű ��, ��, ��, ��     ��\n");
    printf("                          ��                                              ��\n");
    printf("                          ������������������������������������������������������������������������������������������������\n");
    printf("                          ��                                              ��\n");
    printf("                          ��                                              ��\n");
    printf("                          ��                              �̢�            ��\n");
    printf("                          ��                ��==          ��              ��\n");
    printf("                          ��                              �̢�            ��\n");
    printf("                          ��        ��==                  ��              ��\n");
    printf("                          ��           ��        ��==     �̢̢�          ��\n");
    printf("                          ��          ���থ                ��  ��          ��\n");
    printf("                          ��      ...  ll      ��==       �̢̢�          �� \n");
    printf("                          ��                                              ��\n");
    printf("                          ��                                              ��\n");
    printf("                          ������������������������������������������������������������������������������������������������\n");
    Sleep(1000);

}
//// �ʱⰪ ////
void init()
{
    for (i = 0; i < WIDTH; i++)
        enemy[i].con = FALSE;
    //�÷��̾� ��ġ�� �߾�
    player.x = WIDTH / 2;
    player.y = HEIGHT; //����
}
void init2()
{
    for (i = 0; i < WIDTH; i++)
        enemy[i].con = FALSE;
    //�÷��̾� ��ġ�� �߾�
    player.x = 6;
    player.y = 37;
}

//// ���� ���� ó�� ////
/* �� ���� */

void CreateEnemy(int a, int b, int c, int count)
{
    for (i = 0; i < count; i++)
    {
        //�ش� �ε���[i]�� ���� ������ (FALSE �̸� ����)
        if (!enemy[i].con)
        {
            //���� (x��) �������� �� ����, ����(y��)�� ���� ��ġ �׻� ��ġ
            enemy[i].x = rand() % (b + 1 - a) + a;     //a~b���� ������ ���� ���
            enemy[i].y = c - 1; // c= height
            //���� ������ �ε��� [i]�� ���� = TRUE�� ����
            enemy[i].con = TRUE;
            return;
        }
    }
}
/* ���� ������ */
void FallEnemy()
{
    for (i = 0; i < 15; i++)
    {
        //�ش� �ε��� [i]�� ���� ������ (TRUE���) ������ ����
        if (enemy[i].con)
        {

            enemy[i].y--;
            gotoxy(enemy[i].x, HEIGHT - enemy[i].y);
            printf("��");
            gotoxy(enemy[i].x, HEIGHT - enemy[i].y - 1);
            printf("  ");

        }
    }
}
/* ���ϱ� ������ ��(�ٴڿ� ������ ��) ���� */

void DelEnemy(int h) {
    int i;
    for (i = 0; i < WIDTH; i++)
    {
        if (enemy[i].con && enemy[i].y < h)
            enemy[i].con = FALSE;
    }
}
/* �÷��̾ ������ ���� ��� (�й�) �Ǵ� ���迡 ���� ��� ������������ ��� */
int DamagedPlayer()
{
    int i;
    for (i = 0; i < WIDTH; i++)
    {
        //���� ���°� TRUE && ���� ��ġ�� y=0 �� �ٴ� && ���� x�� ��ġ = �÷��̾��� x�� ��ġ
        if (enemy[i].x == player.x)
        {
            // ���� ������ Ȯ��
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
    //���� �ʾ����� FALSE ��ȯ
    return FALSE;
}

//// �÷��̾� ó�� ////
/* Ű �ٿ� ó�� */
int isKeyDown(int key)
{
    //***GetAsyncKey�� Ű�� ���ȴٸ� �ֻ��� ��Ʈ�� 1�� ����, ������ Ű�� ���ȴٸ� ������ ��Ʈ�� 1�� ����
    //0x8000�� �ֻ��� ��Ʈ -> 16������ 2��Ʈ�� 4�� ���� ��Ʈ -> 0x8000 = 1000 0000 0000 0000�� �ǹ�
    // �� ������ ��Ʈ�� 0x0001 -> 0000 0000 0000 0001
    // ���� (GetAsyncKeyState(key) & 0x8000) != 0 �� ���� Ű�� �����ִٸ� ��(TRUE)
    return ((GetAsyncKeyState(key) & 0x8000) != 0);
}

/* �÷��̾� �̵� (��/��) */
void MovePlayer()
{
    gotoxy(player.x, player.y);
    printf("��");
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

    //��ġ ���� ����
    if (player.x < 0)
        player.x = 0;
    if (player.x > WIDTH - 1)
        player.x = WIDTH - 1;
    if (player.y > HEIGHT + 1)
        player.y = HEIGHT;
    if (player.y < 0)
        player.y = 0;


}

//// ���� ȭ�� ��� ////
void PrintGame()
{
    //��� ȭ�� clear

    //�÷��̾� ���
    //for (int i = 0; i < WIDTH; i++)
    //{
    //    if (enemy[i].con)
    //    {
    //        //�� ��ġ�� ���� ���
    //        gotoxy(enemy[i].x, HEIGHT - enemy[i].y);
    //        printf("��");
    //    }
    //}
    gotoxy(0, HEIGHT + 1);
    for (i = 0; i < WIDTH; i++)
        printf("��");
    gotoxy(0, 0);
    for (i = 0; i < WIDTH; i++)
        printf("��");
    gotoxy(0, 0);
    for (i = 0; i < HEIGHT + 1; i++)
    {
        printf("��\n");
    }

    for (i = 0; i < HEIGHT + 2; i++)
    {
        gotoxy(WIDTH, i);
        printf("��\n");
    }


    gotoxy(WIDTH / 2, HEIGHT / 2 - 9);
    printf("��");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 - 9);
    printf("��");
    gotoxy(WIDTH / 2 - 1, HEIGHT / 2 - 9);
    printf("��");
    gotoxy(WIDTH / 2, HEIGHT / 2 + 1 - 8);
    printf("��");
    gotoxy(WIDTH / 2 - 1, HEIGHT / 2 - 8);
    printf("��");
    gotoxy(WIDTH / 2 - 1, HEIGHT / 2 + 1 - 8);
    printf("��");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 - 8);
    printf("��");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 + 1 - 8);
    printf("��");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 + 2 - 8);
    printf("��");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 + 3 - 8);
    printf("��");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 + 4 - 8);
    printf("��");
    gotoxy(WIDTH / 2, HEIGHT / 2 + 4 - 8);
    printf("��");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 + 5 - 8);
    printf("��");
    gotoxy(WIDTH / 2 + 1, HEIGHT / 2 + 6 - 8);
    printf("��");
    gotoxy(WIDTH / 2, HEIGHT / 2 + 6 - 8);
    printf("��");

    gotoxy(WIDTH + 10, HEIGHT / 2 - 11);
    printf("��Ż�� 1STAGE");
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
    printf("       < Ż�� ��� > ");
    gotoxy(WIDTH + 7, HEIGHT / 2 - 9 + 4);
    printf(" ������ �������� ��ֹ��� ");
    gotoxy(WIDTH + 7, HEIGHT / 2 - 9 + 5);
    printf("���ؼ� ���� Ż���� �� �ִ�");
    gotoxy(WIDTH + 7, HEIGHT / 2 - 9 + 6);
    printf("      ���踦 �Ծ��!");
    gotoxy(WIDTH + 7, HEIGHT / 2 - 9 + 9);
    printf("�߾ӿ� �ִ� ���迡 �����ϸ�");
    gotoxy(WIDTH + 7, HEIGHT / 2 - 9 + 10);
    printf("  ���踦 ���� �� �ֽ��ϴ�");
    gotoxy(WIDTH + 5, HEIGHT / 2 - 9 + 13);
    printf("- - - - - - - - - - - - - - - - - -");
    gotoxy(WIDTH + 7, HEIGHT / 2 - 9 + 15);
    printf("          < ���� >");
    gotoxy(WIDTH + 7, HEIGHT / 2 - 9 + 16);
    printf("   ����� �� '��'���Դϴ�");
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
    printf("1 STAGE ��Ż�⿡ �����ϼ̽��ϴ�. ���� 2STAGE ��Ż��� �Ѿ�ڽ��ϱ�?");
    gotoxy(WIDTH / 2 + 7, HEIGHT / 2 + 6);
    printf("[ YES(y) / NO(n) ]");
    gotoxy(WIDTH / 2 + 6, HEIGHT / 2 + 7);
    printf("(y �Ǵ� n�� �����ּ���)\n");
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
    printf("�ι�° �������� ����");
    titleDraw();
    menuDraw();
    system("cls");
    init2();
    system("mode con cols=170 lines=50 | title ��'Ż'�� '��'�� ");

    int row = 1, col = 0; //���� ��ġ �ʱ�ȭ

    CursorView(0);

    GotoXY(XPOS - 3, YPOS - 2);
    printf("  2 STAGE : ���� ã�� ã�� ����");
    sung();
    while (1) //���� start
    {
        print_mazeGame(maze, 40);
        move_maze(maze, &row, &col);
    }
}

void sung()
{
    gotoxy(5, 15);
    printf("        ��Ż�� 2 STAGE\n");
    printf("  = = = = = = = = = = = = = = = = = = = = = = = =\n");
    printf("  =              KEY ESCAPE ROOM                =\n");
    printf("  =                                             =\n");
    printf("  =             <���� �����մϴ�!>              =\n");
    printf("  =                                             =\n");
    printf("  =          ��� ���踦 �� ��������.           =\n");
    printf("  =             ���踦 �� ������                =\n");
    printf("  =   �� �濡�� ���������� Ż���Ҽ� �ֽ��ϴ�.   =\n");
    printf("  =                                             =\n");
    printf("  =                                             =\n");
    printf("  =              KEY SHAPE :  0����               =\n");
    printf("  =                                             =\n");
    printf("  =             PLAYER SHAPE : ��               =\n");
    printf("  =                                             =\n");
    printf("  =                BARRIER : ��                 =\n");
    printf("  =                                             =\n");
    printf("  =                                             =\n");
    printf("  = = = = = = = = = = = = = = = = = = = = = = = =\n ");
}

void CursorView(char show) //Ŀ���� ���ִ� �Լ�
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void GotoXY(int x, int y) //�ܼ� ���� Ŀ�� ��ġ�� �ٲپ� ���ϴ� ���� �̷θ� ����ϱ� ���� �Լ�
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKey() //Ű�� �޾Ƶ��̴� �Լ�
{
    if (_kbhit() != 0) //Ű �Է��� ��ȿ�� ���
    {
        return _getch(); //�Է��� Ű ��ȯ
    }

    return 0; //�׷��� ���� ��� 0��ȯ
}

void print_mazeGame(char maze[][MAX_SIZE], int row) //�̷� frame(Ʋ)�� �׷��ִ� �Լ�
{

    for (int i = 0; i < row; i++)
    {
        GotoXY(XPOS, YPOS + i);
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (maze[i][j] == '1')
                printf("��");
            else if (maze[i][j] == 'y')
                printf("0����");
            else if (maze[i][j] == '0')
                printf("  ");
            else if (maze[i][j] == '2')
                printf(" ");
            else
                printf("��");
        }
        puts("");
    }
}

int is_block(char maze[][MAX_SIZE], int i, int j)
{

    if (maze[i][j] == '1' || maze[i][j] == 'y') //�̷ΰ� ���� ���, ������ ���
        return 1;
    else
        return 0;
}

int is_finish(char maze[][MAX_SIZE], int i, int j)
{

    if (maze[i][j] == 'y') //������ ���
        return 1;
    else
        return 0;
}

void complete_exit(int num) //�Ϸ��� �� ���α׷��� �����Ű�� �Լ�
{
    system("mode con cols=130 lines=30 | title ��'Ż'�� '��'�� ");
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
        printf("                                            �����    ���      ��        ��  ");
        printf("                                                                                              ��         ��  ��     ��        ��    \n");
        printf("                                             �����  �����    ��        ��           \n");
        printf("                                             ��       ��      ��   ��        �� \n");
        printf("                                             ��       ��      ��   �����  �����          \n");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("                                        ������������������������������������������������������������������������������������������������\n");

        printf("                                         ��                                              ��\n");
        printf("                                         ��                                              ��\n");
        printf("                                         ��         %d�ܰ迡�� ������ ����Ǿ����ϴ�.     ��\n", num);
        printf("                                         ��                                              ��\n");

        printf("                                         ��                                              ��\n");
        printf("                                         ������������������������������������������������������������������������������������������������\n");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        exit(0);
    }
}

void complete_exit2() //�Ϸ��� �� ���α׷��� �����Ű�� �Լ�
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
        printf("                   �����   �����    �� ��  �� ��    ����   ��        �����  ������   �����       \n");
        printf("                   ��         ��      ��   ��   ��   ��    ��   ��  ��        ��            ��       ��              \n");
        printf("                   ��         ��      ��   ��        ��    ����   ��        �����      ��       �����    \n");
        printf("                   ��         ��      ��   ��        ��    ��       ��        ��            ��       ��         \n");
        printf("                    �����   �����    ��        ��    ��       �����  �����      ��       �����       \n");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("                                        ������������������������������������������������������������������������������������������������\n");

        printf("                                         ��                                              ��\n");
        printf("                                         ��                                              ��\n");
        printf("                                         ��         2�ܰ迡�� ������ ����Ǿ����ϴ�.     ��\n");
        printf("                                         ��                                              ��\n");
        printf("                                         ��         ���������� ���� Ż���ϼ̽��ϴ�       ��\n");

        printf("                                         ��                                              ��\n");
        printf("                                         ������������������������������������������������������������������������������������������������\n");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        printf("\n ");
        exit(0);
    }
}

void move_maze(char maze[][MAX_SIZE], int* row, int* col) //��ü(���� ���ΰ�?)�� �����̴� �Լ�
{
    int chr; //Ű�� �޾Ƶ��̱� ���� ����
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
            if (!(is_block(maze, i, j))) //���� �ƴ� ��� ��ü�� �ű� �� ����
            {
                maze[*row][j] = '0'; //���� ��Ͽ� 0�� ���� 
                maze[i][j] = 'x'; //����Ű�� �ű� �� x�� ����
                *row -= 1;
            }
            else if (is_finish(maze, i, j)) //������ ���
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
            else if (is_finish(maze, i, j)) //������ ���
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
            else if (is_finish(maze, i, j)) //������ ���
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
            else if (is_finish(maze, i, j)) //������ ���
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
    //�� ���
    gotoxy(0, HEIGHT + 1);
    for (i = 0; i < WIDTH + 2; i++)
        printf("��");
    gotoxy(0, 0);
    for (i = 0; i < WIDTH + 2; i++)
        printf("��");
    gotoxy(0, 0);
    for (i = 0; i < HEIGHT + 1; i++)
        printf("��\n");
    for (i = 0; i < HEIGHT + 1; i++) {
        gotoxy(WIDTH + 1, i + 1);
        printf("��\n");
    }
    gotoxy(25, HEIGHT / 2);
    printf("����\n");
    gotoxy(25, HEIGHT / 2 - 1);
    printf("����\n");
    gotoxy(25, HEIGHT / 2 - 2);
    printf("����\n");
}

void menuDraw() {
    for (i = 0; i < 3; i++) {
        gotoxy(25, 20 - i);
        printf("����\n");
    }
    Sleep(500);
    printf("\n");
    gotoxy(10, 10);
    printf("                                          ��           !KNOCK KNOCK!\n");
    Sleep(500);
    printf("��                                                            ��                   !kNOCK KNOOK!\n");
    Sleep(500);
    printf("��                                                            ��                           !KNOCK KNOCK!\n");
    Sleep(500);
    gotoxy(4, 30);
    printf("����-����������������������������������������������������������������������������������������\n");
    printf("��      ��                                             ��\n");
    printf("��      ��                                             ��\n");
    printf("��      ��             �濡 ���ðڽ��ϱ�?          ��\n");
    //gotoxy(WIDTH / 2 - 10, 12);
    printf("��      ��                                             ��\n");
    //gotoxy(WIDTH / 2 - 10, 13);
    printf("��      ��                                             ��\n");

    //gotoxy(WIDTH / 2 - 10, 14);
    printf("��      ��������-������������������������������������������������������������������������������������");
    printf("\n");
    Sleep(1000);

}

//// main �Լ� ////
void main(void)
{

    system("mode con cols=110 lines=50 | title ��'Ż'�� '��'�� ");
    startpicture();
    system("cls");
    init();


    do {
        //�Ź� ������ ������ �ٸ� ���� �ֱ� ���� �õ尪 ����
        srand((int)malloc(NULL));
        CreateEnemy(3, 29, 41, WIDTH);
        DelEnemy(0);
        FallEnemy();
        PrintGame();
        MovePlayer();
        CursorView(0);
        Sleep(100);

        //������ �ӵ� ������ ���� Sleep ����

    } while (DamagedPlayer() == 0);    //���� ������ �ݺ�
    complete_exit(1);
}
