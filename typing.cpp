#include "myutil.h"

void printEmptyLine()
{
   cout << endl
        << endl;
}

void playLevel(int level, string lesson)
{
   clrscr();
   cout << "\t\t\tPress Esc for Exit anytime\n\n";
   cout << "Correct Count : 0\tIncorrect Count : 0\tTyping speed : 0";
   int correctX = 16, incorrectX = 42, typingSpeedX = 63;
   int statusY = 2;

   printEmptyLine();

   cout << "\t\t\t\tLESSON " << level;
   printEmptyLine();

   cout << lesson << endl;
   int lessonY = 6;

   time_t start, end;
   char inp[lesson.length()];
   float speed;
   int countcorrect = 0, countincorrect = 0;
   char ch;

   start = time(NULL);

   for (int i = 0; i < lesson.length(); i++)
   {
      ch = getSingleChar();
      if (int(ch) == 27)
         break;
      cout << ch;
      inp[i] = ch;

      if (ch == lesson[i])
      {
         countcorrect++;
         gotoxy(correctX, statusY);
         cout << countcorrect;
      }
      else
      {
         countincorrect++;
         gotoxy(incorrectX, statusY);
         cout << countincorrect;

         gotoxy(i, lessonY - 1);
         cout << "*";
      }

      end = time(NULL);
      speed = (i + 1) / difftime(end, start);
      gotoxy(typingSpeedX, statusY);
      cout << speed;

      gotoxy(i + 1, lessonY + 1);
   }
   cout << endl;

   cout << "Press any key to continue...\n";
   getSingleChar();
}

int main()
{
   int choice;
   while (1)
   {
      clrscr();
      cout << "1. Easy Level.\n";
      cout << "2. Medium Level.\n";
      cout << "3. Hard Level.\n";
      cout << "9. Exit\n";
      cout << "Enter Your Choice : ";
      cin >> choice;
      switch (choice)
      {
      case 1:
         playLevel(1, "asdfasdfasdfasdfasdfasdfasdfasdfasdf");
         playLevel(2, "adsfadsfadsfadsfadsfadsfadsfadsfadsf");
         playLevel(3, "afsdasdfasdfafsdfasdfsdfsadsdfasdfas");
         break;
      case 2:
         playLevel(1, ";lkj;kj;k;klj;j;kl;jk;;kkj;jkljljl;");
         break;
      case 3:
         playLevel(2, "assssssdafjk;sdajkl;jkdsj;dfjkjfd;l");
         break;
      case 9:
         return 0;
      default:
         cout << "Invalid Choice\n";
      }
   }
}
