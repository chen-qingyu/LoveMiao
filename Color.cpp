#include "Miao.h"

void Color(string input)
{
    if (input == "red")
    {
        cout << "Red like roses fills my dreams and brings me to the place you rest." << endl;
    }
    else if (input == "orange")
    {
        cout << "Orange is warm, like summer citrus." << endl;
    }
    else if (input == "yellow")
    {
        cout << "Yellow beauty burns gold." << endl;
    }
    else if (input == "green")
    {
        cout << "Green is full of vitality, bringing spring." << endl;
    }
    else if (input == "cyan")
    {
        cout << "Cyan is me." << endl;
    }
    else if (input == "blue")
    {
        cout << "Blue is the sky, vast expanse." << endl;
    }
    else if (input == "purple")
    {
        cout << "Purple is passionate and noble." << endl;
    }
    else if (input == "black")
    {
        cout << "Black the beast descends from shadows." << endl;
    }
    else if (input == "white")
    {
        cout << "White is you." << endl;
    }
    else if (input == "love")
    {
        cout << "I want you, and I love you." << endl;
    }
    else
    {
        cout << "没有选项 " << input << " ， 不如您来添加？" << endl;
    }
}
