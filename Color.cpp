#include "Miao.h"

enum spectrum
{
    red,
    orange,
    yellow,
    green,
    cyan,
    blue,
    purple,
    black,
    white,
    love
} color;

const char *colors[] = {
    "red", "orange", "yellow", "green",
    "cyan", "blue", "purple", "black",
    "white", "love"};

void Color(char *input)
{
    for (color = red; color <= love; color = (enum spectrum)(color + 1))
    {
        if (strcmp(input, colors[color]) == 0)
        {
            break;
        }
    }

    switch (color)
    {
        case red:
            printf("Red like roses fills my dreams and brings me to the place you rest.");
            break;
        case orange:
            printf("Orange is warm, like summer citrus.");
            break;
        case yellow:
            printf("Yellow beauty burns gold.");
            break;
        case green:
            printf("Green is full of vitality, bringing spring.");
            break;
        case cyan:
            printf("Cyan is me.");
            break;
        case blue:
            printf("Blue is the sky, vast expanse.");
            break;
        case purple:
            printf("Purple is passionate and noble.");
            break;
        case black:
            printf("Black the beast descends from shadows.");
            break;
        case white:
            printf("White is you.");
            break;
        case love:
            printf("I want you, and I love you.");
            break;
        default:
            printf("没有选项 %s ， 不如您来添加？", input);
    }
    putchar('\n');
}
