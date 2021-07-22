#include "Miao.h"

void sky(void);
void rainbow(void);
void msg(void);

void Rainbow(void)
{
    PlaySound(_T("Music/One Day.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
    initgraph(WINDOW_LENGTH, WINDOW_HEIGHT);

    sky();
    rainbow();
    msg();

    _getch();
    closegraph();
}

void sky(void)
{
    float H = 190;
    float S = 1;
    float L = 0.7f;

    for (int y = 0; y < WINDOW_HEIGHT; y++)
    {
        L += 0.00036f;
        setlinecolor(HSLtoRGB(H, S, L));
        line(0, y, WINDOW_LENGTH - 1, y);
    }
}

void rainbow(void)
{
    float H = 0;
    float S = 1;
    float L = 0.5;

    setlinestyle(PS_SOLID, 2);
    for (int r = 400; r > 344; r--)
    {
        H += 5;
        setlinecolor(HSLtoRGB(H, S, L));
        circle(950, 700, r);
    }
}

void msg(void)
{
    LOGFONT mode;
    gettextstyle(&mode);
    mode.lfHeight = 30;
    mode.lfItalic = 1;
    _tcscpy(mode.lfFaceName, _T("΢���ź�"));
    mode.lfQuality = PROOF_QUALITY;
    settextstyle(&mode);
    setbkmode(TRANSPARENT);

    TCHAR s[][64] = {
        _T("����"),
        _T("��������Ҷ������뿪��"),
        _T("����һ����ÿһ�춼���������"),
        _T("ÿһ��˲�䶼�����ǵ�С����~")};

    for (int i = 0; i < 4; i++)
    {
        outtextxy(30, 30 * (i + 1), s[i]);
        if (!_kbhit())
        {
            Sleep(1000);
        }
    }
}
