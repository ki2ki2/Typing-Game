#ifndef __myutil__
#define __myutil__

#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

#ifdef __cplusplus__
   #include <cstdlib>
#else
   #include <stdlib.h>
#endif

#define mod 1000000007
#define ll long long int

using namespace std;

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

void clrscr()
{
   system("CLS");
}

char getSingleChar()
{
   while(!kbhit());
   return getch();
}

#endif