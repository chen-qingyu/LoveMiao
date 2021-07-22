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

#pragma comment(lib, "winmm.lib")

#define WINDOW_LENGTH 1024
#define WINDOW_HEIGHT 768

void Circle(void);
void Color(char *input);
void Rainbow(void);
void Star(void);
void Word(void);
