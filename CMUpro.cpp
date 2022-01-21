#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <dos.h>
#include <time.h> 
using namespace std;

int P1=0;
int P2=0;
int movep1=0;//เดินตามช่องarray
int movep2=0;//เดินตามช่องarray
int p1turn=0;//0รอ 1กำลังเดิน -1ตาคนอื่น
int p2turn=0;//0รอ 1กำลังเดิน -1ตาคนอื่น
int LV0[50]={1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1};
int LV1[50]={1,2,2,1,1,1,2,2,1,1,2,1,2,2,2,2,2,2,2,1,2,2,2,1,2,1,2,2,1,1,1,2,1,1,2,1,3,2,1,1,2,2,2,1,2,2,1,2,2,1}; 
int set[50]={};

#define STD_OUTPUT_HANDLE ((DWORD)-11)

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;


void setmap();
void Howtoplay();
void checkmap(int lastmove);
void passcode();//เดะค่อยมาทำ
void space(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

int main(){
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int ST=0;
do{
system("cls");
space(50,5); cout<<" -------------------------- \n"; 
space(50,6); cout<<" |      LostHope Game     | \n"; 
space(50,7); cout<<" --------------------------\n";
space(50,9); cout<<"  1. Start Game \n";
space(50,10); cout<<"  2. How to play *not ready to use now* \n";	 
space(50,11); cout<<"   3. Quit\n";
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
	space(50,5); cout<<" --------------------------- \n"; 
	space(50,6); cout<<" |     choose role P1      | \n"; 
	space(50,7); cout<<" ---------------------------\n";
	if( P1==0){
	space(50,9); cout<<"1. survival \n";
	space(50,10); cout<<"2. Finder \n";
	space(50,11); cout<<"3. Quit \n";
	space(50,13); cout<<"Select option: ";
	char option = getche();
		
	if( option=='1') P1=1;
	else if( option=='2') P1=2;
	else if( option=='3') break;	
	}
	}
    while(P1 == 0 and P2 ==0);
	/////////////////////////////////////
    do{
    system("cls");
	cout<<" -------------------------- \n"; 
	if(P1 == 1)cout << " |   P2 role is Finder  |\n";
	else cout << " |   P2 role is Survival|\n"; 
	cout<<" --------------------------\n";
	cout<<"1. Next \n";
	cout<<"2. Quit \n";
	cout<<"Select option: ";
	char option = getche();
	if(P1 == 1)P2=2;
	else P2=1; 
	if( option=='1') setmap();
	else if( option=='2') break;
	}
    while(P1 >0 and P2>0);
}
}
void walkPY(){
	system("cls");
	for (int i = 0; i < 50; i++)
	{	
		if(i%10==0) cout << "\n";
		
		if(set[i]==1) cout << "# ";
		else if(set[i]==3) cout << "* ";
		else if(set[i]==4) cout << "1 ";
		else if(set[i]==5) cout << "2 ";
		else cout << "_ ";
	}
    cout << "\n";
    do{
	cout<<" -------------------------- \n";
	if(P1 == 1 and movep1 == 0)cout<<" |  Use WASD to move P1   | \n"; 
	else cout<<" |  Use WASD to move P2   | \n"; 
	cout<<" |     Use WASD to move   | \n"; 
	cout<<" --------------------------\n";
	cout<<"1. W(up) ";
	cout<<"         2. S(Down) \n";
	cout<<"3. A(lelf) ";
	cout<<"       4. D(right) \n";
    cout<<"5. Quit(get passcodelevel) *not ready to use now*\n";
	cout<<"Select option: ";
	char option = getche();
	/////////////////////////////////////
	if(P1 == 1){//เพิ่มเลขเดิน
	p1turn +=1;
	if( option=='1') movep1 -= 10;
	else if( option=='2') movep1 += 10;
    else if( option=='3') movep1 -= 1;
    else if( option=='4') movep1 += 1;
	}
	else{
	p2turn +=1;
	if( option=='1') movep2 -= 10;
	else if( option=='2') movep2 += 10;
    else if( option=='3') movep2 -= 1;
    else if( option=='4') movep2 += 1;
	}
	/////////////////////////////////////
	int lastmove=0;//บันทึกการเดิน (เผื่อมันเดินติด)
	if( option=='1') lastmove -= 10;
	else if( option=='2') lastmove += 10;
    else if( option=='3') lastmove -= 1;
    else if( option=='4') lastmove += 1;
	/////////////////////////////////////	
	if( option=='1') checkmap(lastmove);
	else if( option=='2') checkmap(lastmove);
   	else if( option=='3') checkmap(lastmove);
    else if( option=='4') checkmap(lastmove);
    //else if( option=='5') passcode;
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
	cout<<"Select option: ";
	char option = getche();
	if( option=='1') return;	
    }
    while(1);
}
void checkmap(int lastmove){
	system("cls");
	int x;
	cout << movep1;
	cout << p1turn;
	cout << lastmove;
	cin >> x;
}
