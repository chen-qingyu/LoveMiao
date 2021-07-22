#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <mmsystem.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#pragma comment(lib, "winmm.lib")

#define WINDOW_LENGTH 1024
#define WINDOW_HEIGHT 768

void Circle(void);
void Color(string input);
void Rainbow(bool play_music);
void Star(bool play_music);
void Word(bool play_music);
