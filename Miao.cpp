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
        PlaySound(_T("Music/�簮.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
    }
    getchar(); // �Ե������Enter

    puts("\n���������������������ҵ������\n\n"
         "С����������˳�\n\n"
         "���������������С����~\n\n"
         "����~\n\n"
         "\t\t\t\t������ҵ�����\n\n"
         "1: Star\n2: Rainbow\n"
         "3: Word\n4: Circle\n\n"
         "q: �˳�");

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
        PlaySound(_T("Music/�簮.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
    }

    puts("������~~\n");
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
