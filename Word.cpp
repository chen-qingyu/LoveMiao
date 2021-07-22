#include "Miao.h"

void Word(bool play_music)
{
    if (play_music)
    {
        PlaySound(TEXT("Music/Too Far.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
    }
    
    srand(time(NULL));
    initgraph(WINDOW_LENGTH, WINDOW_HEIGHT);

    int x, y;
    TCHAR c[][8] = {_T("I      "), _T("LOVE   "), _T("YOU    ")};

    LOGFONT f;
    gettextstyle(&f);
    f.lfQuality = PROOF_QUALITY;
    settextstyle(&f);
    settextstyle(16, 8, _T("Consolas"));
    settextcolor(LIGHTMAGENTA);
    setlinecolor(MAGENTA);
    setbkcolor(MAGENTA);
    cleardevice();

    for (int i = 0, j = 0; i <= WINDOW_HEIGHT - 1; i++)
    {
        x = (rand() % (WINDOW_LENGTH / 64)) * 64;
        y = (rand() % (WINDOW_HEIGHT / 24)) * 24;
        outtextxy(x, y, c[j++ % 3]);

        line(0, i, WINDOW_LENGTH - 1, i);

        Sleep(10);
        if (i >= WINDOW_HEIGHT - 1)
        {
            i = -1;
        }
        if (_kbhit())
        {
            break;
        }
    }

    _getch();

    closegraph();
}
