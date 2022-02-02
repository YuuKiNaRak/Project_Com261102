#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <dos.h>
#include <time.h> 
using namespace std;

int x = 0 ;
int y = 0 ;
int P1=0;
int P2=0;
int movep1=0;//เดินตามช่องarray
int movep2=0;//เดินตามช่องarray
int p1turn=1;//0รอ 1กำลังเดิน -1ตาคนอื่น
int p2turn=0;//0รอ 1กำลังเดิน -1ตาคนอื่น
int LV1[50]={1,2,4,1,1,1,2,2,1,1,2,1,2,2,2,2,2,2,2,1,2,2,2,2,2,1,2,2,1,1,2,5,2,1,2,1,3,2,1,1,2,2,2,1,2,2,1,2,2,1};
int set[50]={};
int who=0;

#define STD_OUTPUT_HANDLE ((DWORD)-11)

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void time();
void testhowtoplay();
void setmap();
void Howtoplay();
void checkmap(int lastmove,int who);
void passcode();//เดะค่อยมาทำ
void space(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

int main(){
	int randomcolor;
	srand(time(0));
	int a[randomcolor] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int len = 0,x;
    string text;
	len = text.length();
	
	
	
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int ST=0;
do{
system("cls");

	
	space(50,5);
	string text = " -------------------------- \n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];
		//Sleep(250);
    }

	
	
	
space(50,6); cout<<" |      LostHope Game     | \n"; 
space(50,7); cout<<" --------------------------\n";
SetConsoleTextAttribute(h,14);
space(50,9);  cout<<"  1. Start Game \n";
space(50,10); cout<<"  2. How to play  \n";	 
space(50,11); cout<<"  3. Quit\n";
space(50,13); cout<<"Select option: ";
char option = getche();
if( option=='1') ST +=1;
else if( option=='2') Howtoplay();
else if( option=='3') break;	
}while(ST == 0);
/////////////////////////////////////
if(ST == 0){}
else{
    do{
    system("cls");
	SetConsoleTextAttribute(h,4);
	space(50,5); cout<<" --------------------------- \n"; 
	space(50,6); cout<<" |     choose role P1      | \n"; 
	space(50,7); cout<<" ---------------------------\n";
	if( P1==0){
	space(50,9);  cout<<"1. Survival \n";
	space(50,10); cout<<"2. Finder \n";
	space(50,11); cout<<"3. Quit \n";
	space(50,13); cout<<"Select option: ";
	char option = getche();
		
	if( option=='1') P1=1;
	else if( option=='2') P1=2;
	else if( option=='3') break;
	}
	}while(P1 == 0 and P2 ==0);
	/////////////////////////////////////
    do{
    system("cls");
	space(50,5); cout<<" -------------------------- \n"; 
	space(50,6); if(P1 == 1)cout << " |   P2 role is Finder  |\n";
	else cout << " |   P2 role is Survival|\n"; 
	space(50,7); cout<<" --------------------------\n";
	space(50,9); cout<<"1. Next \n";
	space(50,10);cout<<"2. Quit \n";
	space(50,13);cout<<"Select option: ";
	char option = getche();

	if( P1 ==1) P2=2;
	else if( P1 ==2) P2=1;

	if( P1 ==1) p1turn =1;
	else if( P2 == 1 ) p2turn=1;

	if( option=='1') setmap();
	else if( option=='2') break;
	}while(P1 >0 and P2>0);
}
}


void walkPY(){
	do{
	int lastmove=0;//บันทึกการเดิน (เผื่อมันเดินติด)
	system("cls");
	for (int i = 0; i < 50; i++)
	{	
		if(i%10==0){
        cout << "\n";
        for(int y = 0; y < 55; y++){ cout << " ";}
        }
		if(set[i]==1) cout << "# ";
        if(set[i]==2) cout << "_ ";
		if(set[i]==3) cout << "* ";
	    if(set[i]==4){
        cout << "1 ";
        movep1=i;
        }
		if(set[i]==5){
        cout << "2 ";
        movep2=i;
        }
	}
    cout << "\n";
	space(50,7); cout<<" -------------------------- \n";
	space(50,8);if(p1turn == 1)cout<<" |  Use WASD to move P1   | \n"; 
	space(50,8);if(p2turn == 1) cout<<" |  Use WASD to move P2   | \n"; 
	space(50,10); cout<<" --------------------------\n";
	space(50,15); cout<<"Select option: ";
	char option = getche();
	if(p1turn == 1){
    who=1;
	if( option=='w') movep1 -= 10;
	else if( option=='s') movep1 += 10;
    else if( option=='a') movep1 -= 1;
    else if( option=='d') movep1 += 1;
	}
	if(p2turn == 1){
    who=2;
	if( option=='w') movep2 -= 10;
	else if( option=='s') movep2 += 10;
    else if( option=='a') movep2 -= 1;
    else if( option=='d') movep2 += 1;
	}
	/////////////////////////////////////
	if( option=='w') lastmove -= 10;
	else if( option=='s') lastmove += 10;
    else if( option=='a') lastmove -= 1;
    else if( option=='d') lastmove += 1;
	/////////////////////////////////////	
	if( option=='w') checkmap(lastmove,who);
	else if( option=='s') checkmap(lastmove,who);
    else if( option=='a') checkmap(lastmove,who);
    else if( option=='d') checkmap(lastmove,who);
	}
    while(1);
}

void setmap(){
	for (int i = 0; i < 50; i++)
	{
		set[i]=LV1[i];
	}
	walkPY();
}
void Howtoplay(){
    do{
    system("cls");
	cout<<" -------------------------- \n"; 
	cout<<" |        (How)           | \n"; 
	cout<<" --------------------------\n";
	cout<<"1. Back\n";	 
	cout << "2. start\n";
	cout<<"Select option: ";
	char option = getche();
	if( option=='1') return;
	else if(option == '2')testhowtoplay();	
    }
    while(1);
}
void checkmap(int lastmove,int who){
    if(who == 1){
    if(set[movep1] == 1){
    movep1 -= lastmove;
    } 
    else{
        p2turn=1;
        p1turn=0;
        set[movep1]=4;
        set[movep1-lastmove]=2;
        }
    }
    if(who == 2){
    if(set[movep2] == 1){
    movep2 -= lastmove;
    } 
    else{
        p2turn=0;
        p1turn=1;
	    set[movep2]=5;
        set[movep2-lastmove]=2;
    }
    }
}
void time(){
int sec = 30;
while(true){

	system("cls");
	cout << sec << endl;
	sec--;
	Sleep (1000);
}
}
void testhowtoplay(){
	system("cls");
	cout<<"\n----------------\n";
	cout<<"|   How to play  |";
	cout<<"\n----------------";
	cout<<"\n use 1 2 3 4 to move";
	cout<<"\n\n Press '1' to move up";
	cout<<"\n Press '2' to move down";
	cout<<"\n Press '3' to move left";
	cout<<"\n Press '4' to move right";
	cout<<"\n\nPress any key to go back to menu";
	getch();
}
void gameover(){
	system("cls");
	cout<<endl;
	cout<<"\t\t--------------------------"<<endl;
	cout<<"\t\t-------- Game Over -------"<<endl;
	cout<<"\t\t--------------------------"<<endl<<endl;
	cout<<"\t\tPress any key to go back to menu.";
	getch();
}
 
