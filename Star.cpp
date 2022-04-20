#include "Miao.h"

#define MAX 520

struct
{
    double x;
    int y;
    double step;
    int color;
} star[MAX];

void InitStar(int);
void MoveStar(int);
void LoveMiao(void);

void Star(bool play_music)
{
    if (play_music)
    {
        PlaySound(_T("Music/One night.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
    }

    srand(time(NULL));
    initgraph(WINDOW_LENGTH, WINDOW_HEIGHT);
    for (int i = 0; i < MAX; i++)
    {
        InitStar(i);
        star[i].x = rand() % WINDOW_LENGTH;
    }

    while (!_kbhit())
    {
        LoveMiao();
        for (int i = 0; i < MAX; i++)
        {
            MoveStar(i);
        }
        Sleep(5);
    }
    _getch();
    closegraph();
}

void InitStar(int i)
{
    star[i].x = 0;
    star[i].y = rand() % WINDOW_HEIGHT;
    star[i].step = (rand() % 5000) / 1000.0 + 1;
    star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);
    star[i].color = RGB(star[i].color, star[i].color, star[i].color);
}

void MoveStar(int i)
{
    putpixel((int)star[i].x, star[i].y, 0);

    star[i].x += star[i].step;
    if (star[i].x > WINDOW_LENGTH)
    {
        InitStar(i);
    }

    putpixel((int)star[i].x, star[i].y, star[i].color);
}

void LoveMiao(void)
{
    LOGFONT mode;
    gettextstyle(&mode);
    mode.lfHeight = 30;
    mode.lfItalic = 1;
    _tcscpy(mode.lfFaceName, _T("微软雅黑"));
    mode.lfQuality = PROOF_QUALITY;
    settextstyle(&mode);
    setbkmode(TRANSPARENT);

    RECT r = {0, 0, WINDOW_LENGTH, WINDOW_HEIGHT};
    drawtext(_T("未来的路上，还请多多关照~"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
