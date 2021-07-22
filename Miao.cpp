#include "Miao.h"

char *getstr(void);

int main(void)
{
    char *str = NULL;
    char c;
    printf("Play music?(y/n):");
    scanf("%c", &c);
    if (c == 'y' || c == 'Y')
    {
        PlaySound(_T("Music/溢爱.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
    }
    getchar(); // 吃掉多余的Enter

    puts("\n喵，就让这个程序来表达我的心意吧\n\n"
         "小程序按任意键退出\n\n"
         "喵可以在这里添加小程序~\n\n"
         "爱你~\n\n"
         "\t\t\t\t——你家的青喵\n\n"
         "1: Star\n2: Rainbow\n"
         "3: Word\n4: Circle\n\n"
         "q: 退出");

    while (1)
    {
        free(str);
        printf("\nEnter: ");
        str = getstr();
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += ('a'-'A'); // to lower
            }
        }
        if (strcmp(str, "q") == 0)
        {
            break;
        }
        if (str[0] == '\0' || str[0] == '\t' || str[0] == ' ')
        {
            continue;
        }

        if (strcmp(str, "1") == 0)
        {
            Star();
        }
        else if (strcmp(str, "2") == 0)
        {
            Rainbow();
        }
        else if (strcmp(str, "3") == 0)
        {
            Word();
        }
        else if (strcmp(str, "4") == 0)
        {
            Circle();
            continue;
        }
        else
        {
            Color(str);
            continue;
        }
        PlaySound(_T("Music/溢爱.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
    }

    puts("喵喵喵~~\n");
    Sleep(1000);

    return 0;
}

char *getstr(void)
{
    char *tmp, *str = (char *)malloc(10);
    int c = 0, times = 1, number = 0, len = 0;
    if (!str)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    number += times * 10;
    while ((c = getchar()) != '\n')
    {
        if (len == number)
        {
            times++;
            number = times * 10;
            tmp = str;
            str = (char *)realloc(str, number);
            if (str == NULL)
            {
                fprintf(stderr, "ERROR: There was not enough memory.\n");
                exit(-2);
            }
        }
        *(str + len) = c;
        len++;
    }
    str = (char *)realloc(str, len + 1);
    if (str == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }
    *(str + len) = '\0';

    return str;
}
