#include <iostream>
#include <conio.h>
#include <string>
#include "windows.h"
#include <dos.h>
#include<fstream>
#include <time.h> 
#define STD_OUTPUT_HANDLE ((DWORD)-11)

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;
void p1();
void p2();
void gamestart();
void Howtoplay();
void gameover();
void menu();
void role();
void gotoxy( short x, short y ){
    COORD pos{x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
  }
void space(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
char mapset[5][20] = {
"# _ _ # # # _ _ # #",  
"_ # _ _ _ 2 _ _ _ #",    
"_ _ @ _ _ # _ _ # #",  
"_ _ _ # _ # * _ # #",    
"_ _ _ # _ _ # _ 1 #"};
char map[5][20];
int x,y,i,j;
int times=60;
//spawnpoint
int turn=0,P1=0,P2=0;
bool game_runner = true;

int main(){
srand(time(0));
menu();
return 0; 
}
void p1(){
      if(turn==1&&P1==1){
        if(GetAsyncKeyState(0x53)){
            int yc = y+1;
            if(map[yc][x] == '_'){
                map[y][x] = '_'; 
                y++;
                map[y][x] = '1';
            }if(map[yc][x] == '*'){
                map[y][x] = '_';
                y++; 
                map[y][x] = '1';
            }if(map[yc][x] == '@'&&map[yc+1][x] == '_'){
                map[y][x] = '_';
                y++;
                map[y][x] = '1';
                map[y+1][x] = '@';
            }
            turn=2;
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x57)){
            int yc = y-1;
            if(map[yc][x] == '_'){
                map[y][x] = '_'; 
                y--;
                map[y][x] = '1';

            }if(map[yc][x] == '*'){
                map[y][x] = '_'; 
                y--;
                map[y][x] = '1';
            }if(map[yc][x] == '@'&&map[yc-1][x] == '_'){
                map[y][x] = '_';
                y--;
                map[y][x] = '1';
                map[y-1][x] = '@';

            }
            turn=2;
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x44)){
            int xc = x+2;
            if(map[y][xc] == '_'){
                map[y][x] = '_'; 
                x+=2;
                map[y][x] = '1';

            }if(map[y][xc] == '*'){
                map[y][x] = '_'; 
                x+=2;
                map[y][x] = '1';
            }if(map[y][xc] == '@'&&map[y][xc+2] == '_'){
                map[y][x] = '_';
                x+=2;
                map[y][x] = '1';
                map[y][x+2] = '@';

            }
            turn=2;
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x41)){
            int xc = x-2;
            if(map[y][xc] == '_'){
                map[y][x] = '_'; 
                x-=2;
                map[y][x] = '1';
                }if(map[y][xc] == '*'){
                map[y][x] = '_'; 
                x-=2;
                map[y][x] = '1';
                }if(map[y][xc] == '@'&&map[y][xc-2] == '_'){
                map[y][x] = '_';
                x-=2;
                map[y][x] = '1';
                map[y][x-2] = '@';

            }
            turn=2;
            Sleep(200);
            return;
        }
    }
    if(turn==1&&P1==2){
        if(GetAsyncKeyState(0x53)){
            int yc = y+1;
            if(map[yc][x] == '_'){
                map[y][x] = '_'; 
                y++;
                map[y][x] = '1';
            }if(map[yc][x] == '@'&&map[yc+1][x] == '_'){
                map[y][x] = '_';
                y++;
                map[y][x] = '1';
                map[y+1][x] = '@';
            }
            turn=2;
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x57)){
            int yc = y-1;
            if(map[yc][x] == '_'){
                map[y][x] = '_'; 
                y--;
                map[y][x] = '1';

            }if(map[yc][x] == '@'&&map[yc-1][x] == '_'){
                map[y][x] = '_';
                y--;
                map[y][x] = '1';
                map[y-1][x] = '@';

            }
            turn=2;
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x44)){
            int xc = x+2;
            if(map[y][xc] == '_'){
                map[y][x] = '_'; 
                x+=2;
                map[y][x] = '1';

            }if(map[y][xc] == '@'&&map[y][xc+2] == '_'){
                map[y][x] = '_';
                x+=2;
                map[y][x] = '1';
                map[y][x+2] = '@';

            }
            turn=2;
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x41)){
            int xc = x-2;
            if(map[y][xc] == '_'){
                map[y][x] = '_'; 
                x-=2;
                map[y][x] = '1';
                }if(map[y][xc] == '@'&&map[y][xc-2] == '_'){
                map[y][x] = '_';
                x-=2;
                map[y][x] = '1';
                map[y][x-2] = '@';

            }
            turn=2;
            Sleep(200);
            return;
        }
    }
}
void p2(){
if(turn==2&&P2==1){
        if(GetAsyncKeyState(0x53)){
            int jc = j+1;
            if(map[jc][i] == '_'){
                map[j][i] = '_'; 
                j++;
                map[j][i] = '2';
            }if(map[jc][i] == '*'){
                map[j][i] = '_'; 
                j++;
                map[j][i] = '2';
            }if(map[jc][i] == '@'&&map[jc+1][i] == '_'){
                map[j][i] = '_';
                j++;
                map[j][i] = '2';
                map[j+1][i] = '@';

            }
            turn=1;
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x57)){
            int jc = j-1;
            if(map[jc][i] == '_'){
                map[j][i] = '_'; 
                j--;
                map[j][i] = '2';

            }if(map[jc][i] == '*'){
                map[j][i] = '_';
                j--;
                map[j][i] = '2'; 
            }if(map[jc][i] == '@'&&map[jc-1][i] == '_'){
                map[j][i] = '_';
                j--;
                map[j][i] = '2';
                map[j-1][i] = '@';

            }
            turn=1;
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x44)){
            int ic = i+2;
            if(map[j][ic] == '_'){
                map[j][i] = '_'; 
                i+=2;
                map[j][i] = '2';

            }
            if(map[j][ic] == '*'){
                map[j][i] = '_'; 
                i+=2;
                map[j][i] = '2';
            }if(map[j][ic] == '@'&&map[j][ic+2] == '_'){
                map[j][i] = '_';
                i+=2;
                map[j][i] = '2';
                map[j][i+2] = '@';

            }
            turn=1;
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x41)){
            int ic = i-2;
            if(map[j][ic] == '_'){
                map[j][i] = '_'; 
                i-=2;
                map[j][i] = '2';
            }if(map[j][ic] == '*'){
                map[j][i] = '_'; 
                i-=2;
                map[j][i] = '2';
            }if(map[j][ic] == '@'&&map[j][ic-2] == '_'){
                map[j][i] = '_';
                i-=2;
                map[j][i] = '2';
                map[j][i-2] = '@';
            }
            turn=1;
            Sleep(200);
            return;
        }
    
    }
if(turn==2&&P2==2){
        if(GetAsyncKeyState(0x53)){
            int jc = j+1;
            if(map[jc][i] == '_'){
                map[j][i] = '_'; 
                j++;
                map[j][i] = '2';
            }if(map[jc][i] == '@'&&map[jc+1][i] == '_'){
                map[j][i] = '_';
                j++;
                map[j][i] = '2';
                map[j+1][i] = '@';

            }
            turn=1;
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x57)){
            int jc = j-1;
            if(map[jc][i] == '_'){
                map[j][i] = '_'; 
                j--;
                map[j][i] = '2';

            }if(map[jc][i] == '@'&&map[jc-1][i] == '_'){
                map[j][i] = '_';
                j--;
                map[j][i] = '2';
                map[j-1][i] = '@';

            }
            turn=1;
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x44)){
            int ic = i+2;
            if(map[j][ic] == '_'){
                map[j][i] = '_'; 
                i+=2;
                map[j][i] = '2';

            }if(map[j][ic] == '@'&&map[j][ic+2] == '_'){
                map[j][i] = '_';
                i+=2;
                map[j][i] = '2';
                map[j][i+2] = '@';

            }
            turn=1;
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x41)){
            int ic = i-2;
            if(map[j][ic] == '_'){
                map[j][i] = '_'; 
                i-=2;
                map[j][i] = '2';
            }if(map[j][ic] == '@'&&map[j][ic-2] == '_'){
                map[j][i] = '_';
                i-=2;
                map[j][i] = '2';
                map[j][i-2] = '@';
            }
            turn=1;
            Sleep(200);
            return;
        }
    
    }
    }
void Howtoplay(){
	system("cls");
	cout<<"\n----------------\n";
	cout<<"|   How to play  |";
	cout<<"\n----------------";
	cout<<"\n use 1 2 3 4 to move";
	cout<<"\n\n Press 'w' to move up";
	cout<<"\n Press 's' to move down";
	cout<<"\n Press 'a' to move left";
	cout<<"\n Press 'd' to move right";
	cout<<"\n\nPress any key to go back to menu";
	getch();
}
void gameover(){
	system("cls");
	cout<<endl;
	space(50,5);cout<<"\t\t--------------------------"<<endl;
	space(50,6);cout<<"\t\t-------- Game Over -------"<<endl;
	space(50,7);cout<<"\t\t--------------------------"<<endl<<endl;
	space(47,8);cout<<"\t\tPress any key to go back to menu.";
    P1=0;
    P2=0;
    turn=0;
    getche();
    menu();

}
void gamestart(){
    for(int r=0;r<5;r++){
        for(int c=0;c<20;c++){
    map[r][c] = mapset[r][c];
        }
    }
    for(int r=0;r<5;r++){
        for(int c=0;c<20;c++){
            if(map[r][c]=='1') {
                y=r;
                x=c;
            }if(map[r][c]=='2') {
                j=r;
                i=c;
            }
        }
     }
     Sleep(100);
    while(game_runner == true){
    system("cls");
        for(int dp=0;dp<5;dp++){
            space(50,dp+5);
            cout << map[dp] << endl;
        }
    gotoxy(45,10); 
    cout<<" -------------------------- \n";
    if(turn==1){gotoxy(45,11); 
                cout << " |  Use WASD to move P1  | \n"; }
    else {gotoxy(45,11);  
    cout << " |  Use WASD to move P2  | \n"; }
    gotoxy(45,12); 
    cout<<" -------------------------- \n";
    system("pause>nul");
            p1();
            p2();
    }
}
void menu(){
do{
system("cls");
SetConsoleTextAttribute(h,6);
space(50,5); cout<<" -------------------------- \n"; 
space(50,6); cout<<" |      LostHope Game     | \n"; 
space(50,7); cout<<" --------------------------\n";
SetConsoleTextAttribute(h,14);
space(50,9);  cout<<"  1. Start Game \n";
space(50,10); cout<<"  2. How to play  \n";	 
space(50,11); cout<<"  3. Quit\n";
space(50,13); cout<<"Select option: ";
    char option = getche();
    if( option=='1') role();
    else if( option=='2') Howtoplay(); 
    else if ( option=='3') {
        system("cls");
        return; }
}while(1);
}
void role(){
    while(P1==0){
     system("cls");
	SetConsoleTextAttribute(h,4);
	space(50,5); cout<<" --------------------------- \n"; 
	space(50,6); cout<<" |     choose role P1      | \n"; 
	space(50,7); cout<<" ---------------------------\n";
        space(50,9);  cout<<"1. Survival \n";
        space(50,10); cout<<"2. Finder \n";
        space(50,11); cout<<"3. Quit \n";
        space(50,13); cout<<"Select option: ";
        char option = getche();
        if( option=='1') P1=1;
        else if( option=='2') P1=2;
        else if( option=='3') menu();
    }
    system("cls");
	space(50,5); cout<<" -------------------------- \n"; 
	space(50,6); if(P1 == 1)cout << " |   P2 role is Finder  |\n";
	else cout << " |   P2 role is Survival|\n"; 
	space(50,7); cout<<" --------------------------\n";
    if( P1 ==1) P2=2;
	else if( P1 ==2) P2=1;

	if( P1 ==1) turn =1;
	else if( P2 == 1 ) turn=2;
	space(50,9); cout<<"1. Next \n";
	space(50,10);cout<<"2. Quit \n";
	space(50,13);cout<<"Select option: ";
	char option = getche();
    if(option=='1') gamestart();
    else if( option=='2') menu();

}
