#include "Miao.h"

int main(void)
{
    string input; // input string
    bool play_music = false;
    cout << "Play music?(y/n): ";
    cin >> input;
    if (input == "y" || input == "Y")
    {
        play_music = true;
    }

    if (play_music)
    {
        PlaySound(_T("Music/�簮.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
    }
    cin.get(); // �Ե�����Ļ��з�

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
        cout << "\nEnter: ";
        std::getline(cin, input);

        for (int i = 0; input[i] != '\0'; i++)
        {
            if (input[i] >= 'A' && input[i] <= 'Z')
            {
                input[i] += ('a'-'A'); // to lower
            }
        }

        // quit
        if (input == "q")
        {
            break;
        }
        // ignore space
        if (input[0] == '\0' || input[0] == '\t' || input[0] == ' ')
        {
            continue;
        }

        /*
            functions.
        */
        if (input == "1")
        {
            Star(play_music);
        }
        else if (input == "2")
        {
            Rainbow(play_music);
        }
        else if (input == "3")
        {
            Word(play_music);
        }
        else if (input == "4")
        {
            Circle();
            continue;
        }
        else
        {
            Color(input);
            continue;
        }

        if (play_music)
        {
            PlaySound(_T("Music/�簮.wav"), NULL, SND_ASYNC | SND_NODEFAULT);
        }
    }

    cout << "������~~" << endl;
    Sleep(1000); // wait 1000ms

    return 0;
}
