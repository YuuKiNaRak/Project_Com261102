#include <iostream>
#include <conio.h>
#include <string>
#include "windows.h"
#include <dos.h>
#include <time.h> 
#define STD_OUTPUT_HANDLE ((DWORD)-11)

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

using namespace std;
void p1();
void p2();
void gamestart();
void Howtoplay();
void gameover();
void gotoxy( short x, short y ){
    COORD pos{x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
  }
void space(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
char map[5][20] = {
"# _ _ # # # _ _ # #",    
"_ # _ _ _ 2 _ _ _ #",    
"_ _ @ _ _ # _ _ # #",   
"_ _ _ # _ # * _ # #",    
"_ _ _ # _ _ # _ 1 #"};

int x,y,i,j;
//spawnpoint
int turn=0;

bool game_runner = true;

int main(){
srand(time(0));
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
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
    if( option=='1') gamestart();
    else if( option=='2') Howtoplay(); 
    else if ( option=='3') {
        system("cls");
        return 0; }
}while(1);
return 0; 
}
void p1(){
    if(turn==1){
        if(GetAsyncKeyState(VK_DOWN)){
            int yc = y+1;
            if(map[yc][x] == '_'){
                map[y][x] = '_'; 
                y++;
                map[y][x] = '1';
            }if(map[yc][x] == '*'){
                map[y][x] = '_';
                y++; 
                map[y][x] = '1';
                gameover();
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
        if(GetAsyncKeyState(VK_UP)){
            int yc = y-1;
            if(map[yc][x] == '_'){
                map[y][x] = '_'; 
                y--;
                map[y][x] = '1';

            }if(map[yc][x] == '*'){
                map[y][x] = '_'; 
                y--;
                map[y][x] = '1';
                gameover();
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
        if(GetAsyncKeyState(VK_RIGHT)){
            int xc = x+2;
            if(map[y][xc] == '_'){
                map[y][x] = '_'; 
                x+=2;
                map[y][x] = '1';

            }if(map[y][xc] == '*'){
                map[y][x] = '_'; 
                x+=2;
                map[y][x] = '1';
                gameover();
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
        if(GetAsyncKeyState(VK_LEFT)){
            int xc = x-2;
            if(map[y][xc] == '_'){
                map[y][x] = '_'; 
                x-=2;
                map[y][x] = '1';
                }if(map[y][xc] == '*'){
                map[y][x] = '_'; 
                x-=2;
                map[y][x] = '1';
                gameover();
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
if(turn==2){
        if(GetAsyncKeyState(VK_DOWN)){
            int jc = j+1;
            if(map[jc][i] == '_'){
                map[j][i] = '_'; 
                j++;
                map[j][i] = '2';
            }if(map[jc][i] == '*'){
                map[j][i] = '_'; 
                j++;
                map[j][i] = '2';
                gameover();
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
        if(GetAsyncKeyState(VK_UP)){
            int jc = j-1;
            if(map[jc][i] == '_'){
                map[j][i] = '_'; 
                j--;
                map[j][i] = '2';

            }if(map[jc][i] == '*'){
                map[j][i] = '_';
                j--;
                map[j][i] = '2'; 
                gameover();
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
        if(GetAsyncKeyState(VK_RIGHT)){
            int ic = i+2;
            if(map[j][ic] == '_'){
                map[j][i] = '_'; 
                i+=2;
                map[j][i] = '2';

            }if(map[j][ic] == '*'){
                map[j][i] = '_'; 
                i+=2;
                map[j][i] = '2';
                gameover();
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
        if(GetAsyncKeyState(VK_LEFT)){
            int ic = i-2;
            if(map[j][ic] == '_'){
                map[j][i] = '_'; 
                i-=2;
                map[j][i] = '2';
            }if(map[j][ic] == '*'){
                map[j][i] = '_'; 
                i-=2;
                map[j][i] = '2';
                gameover();
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
    getche();
}
void gamestart(){
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
     turn = rand()%2+1;
    while(game_runner == true){
    system("cls");
        for(int dp=0;dp<5;dp++){
            gotoxy(50,dp+10);
            cout << map[dp] << endl;
        }
    system("pause>nul");
            p1();
            p2();
    }
}
