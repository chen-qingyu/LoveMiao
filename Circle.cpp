#include "Miao.h"

#define R 5
#define X 10
#define Y 10

void Circle(void)
{
    int x, y;
    double m;
    for (y = R; y >= -R; y--)
    {
        m = 2 * sqrt(R * R - y * y);
        for (x = 1; x < X + R - m; x++)
        {
            printf(" ");
        }
        printf("*");

        for (; x < X + R + m; x++)
        {
            printf(" ");
        }
        printf("*");

        printf("\n");
    }
    double sx, sy;
    double dx = 1.0 / 16, dy = 1.0 / 16;
    for (sy = 1.0; sy >= 0; sy -= dy, putchar('\n'))
    {
        for (sx = 0.0; sx < 3.141; sx += dx)
        {
            putchar(" *"[sy > 0 != sin(sx) < sy]);
        }
    }
    printf("\n");
    printf("\n这是一幅山水画\n");
}
