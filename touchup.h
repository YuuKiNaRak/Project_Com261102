#include <iostream>
#include <conio.h>
#include <string>
#include "windows.h"
#include <dos.h>
#include<fstream>
#include <time.h> 
#include <stdlib.h>


using namespace std;
COORD CursorPosition;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy( short x, short y ){
    COORD pos{x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
  }
void space(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void loadingscreen(){
    for(int i=0;i<10;i++){
      gotoxy(49,5+i);
              for(int c=0;c<6;c++){
				cout << "\1\1\1\1\1"; 
                Sleep(1);
              }
              cout<<endl;
    }
    for(int i=0;i<10;i++){
      gotoxy(49,5+i);
     cout <<"                              ";			
     Sleep(50);
     cout<<endl;
    }
}
void overscreen(){
    for(int i=0;i<12;i++){
      gotoxy(45,5+i);
              for(int c=0;c<6;c++){
				cout << "\2\2\2\2\2\2"; 
                Sleep(1);
              }
              cout<<endl;
    }
    for(int i=0;i<12;i++){
      gotoxy(45,5+i);
     cout <<"                                    ";			
     Sleep(50);
     cout<<endl;
    }
}
void Howtoplay(){
	system("cls");
    int randomcolor;
	srand(time(0));
	int a[randomcolor] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int len = 0,x;
    string text;
	len = text.length();
	space(52,5); text = "---------------- \n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	space(52,6); text = "|  How to play | \n ";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	space(52,7); text = "---------------- \n ";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	space(50,9); text = "use W A S D to move \n ";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	space(50,10); text = "Press 'w' to move up \n ";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	space(50,11); text = "Press 's' to move down \n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	space(50,12); text = "Press 'a' to move left \n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	space(50,13); text = "Press 'd' to move right \n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	space(45,15); text = "Press any key to go back to menu \n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	getche();
	overscreen();
}
void p1winassur(){
      int randomcolor;
	srand(time(0));
	int a[randomcolor] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int len = 0,x;
    string text;
	len = text.length();
	cout<<endl;

	gotoxy(35,5); text = "\t\t--------------------------\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	gotoxy(35,6); text = "\t\t---- P1 You Escaped ----\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	gotoxy(35,7); text = "\t\t--------------------------\n\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	gotoxy(47,8); cout << "   /\\                 /\\";
    gotoxy(47,9); cout <<"  /__\\   /\\_____/\\   /__\\";
    gotoxy(47,10); cout <<"  |. |_=_|. . . .|_=_|. |";
    gotoxy(47,11); cout <<"  |. |. .|  ___  |. .|. |";
    gotoxy(47,12); cout <<"  |. |   | |   | |   |. |";
    gotoxy(47,13); cout <<"__|__|___|_|___|_|___|__|__";
                        
	gotoxy(32,15); text = "\t\tPress any key to continue.";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
}
void p2winassur(){
      int randomcolor;
	srand(time(0));
	int a[randomcolor] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int len = 0,x;
    string text;
	len = text.length();
	cout<<endl;

	gotoxy(35,5); text = "\t\t--------------------------\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	gotoxy(35,6); text = "\t\t---- P2 You Escaped ----\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	gotoxy(35,7); text = "\t\t--------------------------\n\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	gotoxy(47,8); cout << "   /\\                 /\\";
    gotoxy(47,9); cout <<"  /__\\   /\\_____/\\   /__\\";
    gotoxy(47,10); cout <<"  |. |_=_|. . . .|_=_|. |";
    gotoxy(47,11); cout <<"  |. |. .|  ___  |. .|. |";
    gotoxy(47,12); cout <<"  |. |   | |   | |   |. |";
    gotoxy(47,13); cout <<"__|__|___|_|___|_|___|__|__";
                        
	gotoxy(32,15); text = "\t\tPress any key to continue.";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
}
void p1winasfin(){
      int randomcolor;
	srand(time(0));
	int a[randomcolor] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int len = 0,x;
    string text;
	len = text.length();
	cout<<endl;

	gotoxy(35,5); text = "\t\t--------------------------\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	gotoxy(35,6); text = "\t\t---- P2 You Got Caught----\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	gotoxy(35,7); text = "\t\t--------------------------\n\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	gotoxy(55,8); cout << "  _____";
    gotoxy(55,9); cout <<" /     \\";
    gotoxy(55,10); cout <<"| () () |";
    gotoxy(55,11); cout <<" \\  ^  /";
    gotoxy(55,12); cout <<"  |||||";
    gotoxy(55,13); cout <<"  |||||";

	gotoxy(32,15); text = "\t\tPress any key to continue.";	
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
}
void p2winasfin(){
      int randomcolor;
	srand(time(0));
	int a[randomcolor] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int len = 0,x;
    string text;
	len = text.length();
	cout<<endl;

	gotoxy(35,5); text = "\t\t---------------------------\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	gotoxy(35,6); text = "\t\t---- P1 You Got Caught ----\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	gotoxy(35,7); text = "\t\t---------------------------\n\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	gotoxy(55,8); cout << "  _____";
    gotoxy(55,9); cout <<" /     \\";
    gotoxy(55,10); cout <<"| () () |";
    gotoxy(55,11); cout <<" \\  ^  /";
    gotoxy(55,12); cout <<"  |||||";
    gotoxy(55,13); cout <<"  |||||";

	gotoxy(32,15); text = "\t\tPress any key to continue.";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
}
void opening(){
	int randomcolor = rand()%7+9;
	SetConsoleTextAttribute(h,randomcolor);
	gotoxy(40,5);
	cout << "X"<<endl;
	gotoxy(40,6);
	cout << "X"<<endl;
	gotoxy(40,7);
	cout << "X"<<endl;
	gotoxy(40,8);
	cout << "X"<<endl;
	gotoxy(40,9);
	cout << "X"<<endl;
	gotoxy(40,10);
	cout << "X"<<endl;
	gotoxy(40,11);
	cout << "X X X X X"<<endl;
	Sleep(200);
	gotoxy(40+11,5);
	cout << "X X X X X"<<endl;
	gotoxy(40+11,6);
	cout << "X       X"<<endl;
	gotoxy(40+11,7);
	cout << "X       X"<<endl;
	gotoxy(40+11,8);
	cout << "X       X"<<endl;
	gotoxy(40+11,9);
	cout << "X       X"<<endl;
	gotoxy(40+11,10);
	cout << "X       X"<<endl;
	gotoxy(40+11,11);
	cout << "X X X X X"<<endl;
	Sleep(200);
	gotoxy(40+22,5);
	cout << "X X X X X"<<endl;
	gotoxy(40+22,6);
	cout << "X        "<<endl;
	gotoxy(40+22,7);
	cout << "X        "<<endl;
	gotoxy(40+22,8);
	cout << "X X X X X"<<endl;
	gotoxy(40+22,9);
	cout << "        X"<<endl;
	gotoxy(40+22,10);
	cout << "        X"<<endl;
	gotoxy(40+22,11);
	cout << "X X X X X"<<endl;
	Sleep(200);
	gotoxy(40+33,5);
	cout << "X X X X X"<<endl;
	gotoxy(40+33,6);
	cout << "    X    "<<endl;
	gotoxy(40+33,7);
	cout << "    X    "<<endl;
	gotoxy(40+33,8);
	cout << "    X    "<<endl;
	gotoxy(40+33,9);
	cout << "    X    "<<endl;
	gotoxy(40+33,10);
	cout << "    X    "<<endl;
	gotoxy(40+33,11);
	cout << "    X    "<<endl;
	Sleep(200);
	gotoxy(40,5+10);
	cout << "X       X"<<endl;
	gotoxy(40,5+10+1);
	cout << "X       X"<<endl;
	gotoxy(40,5+10+2);
	cout << "X       X"<<endl;
	gotoxy(40,5+10+3);
	cout << "X X X X X"<<endl;
	gotoxy(40,5+10+4);
	cout << "X       X"<<endl;
	gotoxy(40,5+10+5);	
	cout << "X       X"<<endl;
	gotoxy(40,5+10+6);
	cout << "X       X"<<endl;
	Sleep(200);
	gotoxy(40+11,5+10);
	cout << "X X X X X"<<endl;
	gotoxy(40+11,5+10+1);
	cout << "X       X"<<endl;
	gotoxy(40+11,5+10+2);
	cout << "X       X"<<endl;
	gotoxy(40+11,5+10+3);
	cout << "X       X"<<endl;
	gotoxy(40+11,5+10+4);
	cout << "X       X"<<endl;
	gotoxy(40+11,5+10+5);
	cout << "X       X"<<endl;
	gotoxy(40+11,5+10+6);
	cout << "X X X X X"<<endl;
	Sleep(200);
	gotoxy(40+22,5+10);
	cout << "X X X X X"<<endl;
	gotoxy(40+22,5+10+1);
	cout << "X       X"<<endl;
	gotoxy(40+22,5+10+2);
	cout << "X       X"<<endl;
	gotoxy(40+22,5+10+3);
	cout << "X X X X X"<<endl;
	gotoxy(40+22,5+10+4);
	cout << "X"<<endl;
	gotoxy(40+22,5+10+5);
	cout << "X"<<endl;
	gotoxy(40+22,5+10+6);
	cout << "X"<<endl;
	Sleep(200);
	gotoxy(40+33,5+10);
	cout << "X X X X X"<<endl;
	gotoxy(40+33,5+10+1);
	cout << "X        "<<endl;
	gotoxy(40+33,5+10+2);
	cout << "X        "<<endl;
	gotoxy(40+33,5+10+3);
	cout << "X X X X X"<<endl;
	gotoxy(40+33,5+10+4);
	cout << "X"<<endl;
	gotoxy(40+33,5+10+5);
	cout << "X"<<endl;
	gotoxy(40+33,5+10+6);
	cout << "X X X X X"<<endl;
	Sleep(200);
	
}