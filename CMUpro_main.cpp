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
class point{
public:
    int pts;
};
void p1();
void p2();
void gamestart();
void Howtoplay();
void gameover();
void menu();
void role();
void nextmap();
void gotoxy( short x, short y ){
    COORD pos{x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
  }
void space(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
char mapset1[10][60] = {
"# _ 1 # # # _ * # #",  
"_ # _ _ _ _ _ _ _ #",    
"_ _ _ _ _ # _ _ # #",  
"_ 2 _ # _ # * _ # #",    
"_ _ _ # _ _ # _ _ #"};
char mapset2[10][60] = {
"_ _ _ * # _ # _ _ _",  
"_ # # _ _ _ _ _ # _",    
"_ # # _ # _ # _ # _",  
"_ _ _ # _ # * _ # #",    
//"_ _ _ _ _ _ _ _ # #",
"1 # * # _ # # _ _ 2"};
char mapset3[10][60] = {
"1 _ # * # _ _ _ _ _",  
"_ _ _ _ _ _ # _ # _",    
"_ # _ # _ # _ _ # _",  
"_ # _ # _ # _ _ # _",    
"# * _ _ _ _ * _ # 2"};
char mapset4[10][60] = {
"F O _ # # # _ * # #",  
"_ @ _ _ @ 2 _ _ _ #",    
"_ _ @ _ _ # _ _ # #",  
"_ _ _ # _ # * _ # #",    
"_ _ _ # _ _ # _ 1 #"};
char mapset5[10][60] = {
"F I _ # # # _ * # #",  
"_ @ _ _ @ 2 _ _ _ #",    
"_ _ @ _ _ # _ _ # #",  
"_ _ _ # _ # * _ # #",    
"_ _ _ # _ _ # _ 1 #"};
char map[10][60];
int x,y,i,j;
int times=60;
//spawnpoint
int turn=0,P1=0,P2=0;//determide turn and role 1=sur 2=finder
bool game_runner = false;
point play1;
point play2;
int maxpts;
int maptemp=1;

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
                turn=2;
            }if(map[yc][x] == '*'){
                map[y][x] = '_';
                y++; 
                map[y][x] = '1';
                play1.pts++;
                turn=2;
            }if(map[yc][x] == '@'&&map[yc+1][x] == '_'){
                map[y][x] = '_';
                y++;
                map[y][x] = '1';
                map[y+1][x] = '@';
                turn=2;
            }
            if(map[yc][x] == ' ' or map[yc][x] == '#')turn=1;
			if(map[yc][x] == '2'){
				map[yc][x] == '1';
				gameover();
			}

            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x57)){
            int yc = y-1;
            if(map[yc][x] == '_'){
                map[y][x] = '_'; 
                y--;
                map[y][x] = '1';
                turn=2;

            }if(map[yc][x] == '*'){
                map[y][x] = '_'; 
                y--;
                map[y][x] = '1';
                play1.pts++;
                turn=2;
            }if(map[yc][x] == '@'&&map[yc-1][x] == '_'){
                map[y][x] = '_';
                y--;
                map[y][x] = '1';
                map[y-1][x] = '@';
                turn=2;
            }
            if(map[yc][x] == ' ' or map[yc][x] == '#')turn=1;
			if(map[yc][x] == '2'){
				map[yc][x] == '1';
				gameover();
			}
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x44)){
            int xc = x+2;
            if(map[y][xc] == '_'){
                map[y][x] = '_'; 
                x+=2;
                map[y][x] = '1';
                turn=2;
            }if(map[y][xc] == '*'){
                map[y][x] = '_';
                x+=2;
                map[y][x] = '1';
                play1.pts++;
                turn=2;
            }if(map[y][xc] == '@'&&map[y][xc+2] == '_'){
                map[y][x] = '_';
                x+=2;
                map[y][x] = '1';
                map[y][x+2] = '@';
                turn=2;

            }
            if(map[y][xc] == ' ' or map[y][xc] == '#')turn=1;
			if(map[y][xc] == '2'){
				map[y][xc] == '1';
				gameover();
			}
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x41)){
            int xc = x-2;
            if(map[y][xc] == '_'){
                map[y][x] = '_'; 
                x-=2;
                map[y][x] = '1';
                turn=2;
                }if(map[y][xc] == '*'){
                map[y][x] = '_'; 
                x-=2;
                map[y][x] = '1';
                play1.pts++;
                turn=2;
                }if(map[y][xc] == '@'&&map[y][xc-2] == '_'){
                map[y][x] = '_';
                x-=2;
                map[y][x] = '1';
                map[y][x-2] = '@';
                turn=2;

            }
            if(map[y][xc] == ' ' or map[y][xc] == '#')turn=1;
			if(map[y][xc] == '2'){
				map[y][xc] == '1';
				gameover();
			}
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
                turn=2;
            }if(map[yc][x] == '@'&&map[yc+1][x] == '_'){
                map[y][x] = '_';
                y++;
                map[y][x] = '1';
                map[y+1][x] = '@';
                turn=2;
            }
            if(map[yc][x] == ' ' or map[yc][x] == '#')turn=1;
			if(map[yc][x] == '2'){
				map[yc][x] == '1';
				gameover();
			}
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x57)){
            int yc = y-1;
            if(map[yc][x] == '_'){
                map[y][x] = '_'; 
                y--;
                map[y][x] = '1';
                turn=2;
            }if(map[yc][x] == '@'&&map[yc-1][x] == '_'){
                map[y][x] = '_';
                y--;
                map[y][x] = '1';
                map[y-1][x] = '@';
                turn=2;
            }
            if(map[yc][x] == ' ' or map[yc][x] == '#')turn=1;
			if(map[yc][x] == '2'){
				map[yc][x] == '1';
				gameover();
			}
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x44)){
            int xc = x+2;
            if(map[y][xc] == '_'){
                map[y][x] = '_'; 
                x+=2;
                map[y][x] = '1';
                turn=2;
            }if(map[y][xc] == '@'&&map[y][xc+2] == '_'){
                map[y][x] = '_';
                x+=2;
                map[y][x] = '1';
                map[y][x+2] = '@';
                turn=2;
            }
            if(map[y][xc] == ' ' or map[y][xc] == '#')turn=1;
			if(map[y][xc] == '2'){
				map[y][xc] == '1';
				gameover();
			}
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x41)){
            int xc = x-2;
            if(map[y][xc] == '_'){
                map[y][x] = '_'; 
                x-=2;
                map[y][x] = '1';
                turn=2;
                }if(map[y][xc] == '@'&&map[y][xc-2] == '_'){
                map[y][x] = '_';
                x-=2;
                map[y][x] = '1';
                map[y][x-2] = '@';
                turn=2;
            }
            if(map[y][xc] == ' ' or map[y][xc] == '#')turn=1;
			if(map[y][xc] == '2'){
				map[y][xc] == '1';
				gameover();
			}
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
                turn=1;
            }if(map[jc][i] == '*'){
                map[j][i] = '_'; 
                j++;
                map[j][i] = '2';
                play2.pts++;
                turn=1;
            }if(map[jc][i] == '@'&&map[jc+1][i] == '_'){
                map[j][i] = '_';
                j++;
                map[j][i] = '2';
                map[j+1][i] = '@';
                turn=1;
            }
            if(map[jc][i] == ' ' or map[jc][i] == '#')turn=2;
			if(map[jc][i] == '1' ){
				map[jc][i] == '2';
				gameover();
			}
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x57)){
            int jc = j-1;
            if(map[jc][i] == '_'){
                map[j][i] = '_'; 
                j--;
                map[j][i] = '2';
                turn=1;
            }if(map[jc][i] == '*'){
                map[j][i] = '_';
                j--;
                map[j][i] = '2'; 
                play2.pts++;
                turn=1;
            }if(map[jc][i] == '@'&&map[jc-1][i] == '_'){
                map[j][i] = '_';
                j--;
                map[j][i] = '2';
                map[j-1][i] = '@';
                turn=1;
            }
            if(map[jc][i] == ' ' or map[jc][i] == '#')turn=2;
			if(map[jc][i] == '1' ){
				map[jc][i] == '2';
				gameover();
				
			}
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x44)){
            int ic = i+2;
            if(map[j][ic] == '_'){
                map[j][i] = '_'; 
                i+=2;
                map[j][i] = '2';
                turn=1;
            }
            if(map[j][ic] == '*'){
                map[j][i] = '_'; 
                i+=2;
                map[j][i] = '2';
                play2.pts++;
                turn=1;
            }if(map[j][ic] == '@'&&map[j][ic+2] == '_'){
                map[j][i] = '_';
                i+=2;
                map[j][i] = '2';
                map[j][i+2] = '@';
                turn=1;
            }
            if(map[j][ic] == ' ' or map[j][ic] == '#')turn=2;
			if(map[j][ic] == '1' ){
				map[j][ic] == '2';
				gameover();
			}
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x41)){
            int ic = i-2;
            if(map[j][ic] == '_'){
                map[j][i] = '_'; 
                i-=2;
                map[j][i] = '2';
                turn=1;
            }if(map[j][ic] == '*'){
                map[j][i] = '_'; 
                i-=2;
                map[j][i] = '2';
                play2.pts++;
                turn=1;
            }if(map[j][ic] == '@'&&map[j][ic-2] == '_'){
                map[j][i] = '_';
                i-=2;
                map[j][i] = '2';
                map[j][i-2] = '@';
                turn=1;
            }
            if(map[j][ic] == ' ' or map[j][i] == '#')turn=2;
			if(map[j][ic] == '1' ){
				map[j][ic] == '2';
				gameover();
			}
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
                turn=1;
            }if(map[jc][i] == '@'&&map[jc+1][i] == '_'){
                map[j][i] = '_';
                j++;
                map[j][i] = '2';
                map[j+1][i] = '@';
                turn=1;
            }
            if(map[jc][i] == ' ' or map[jc][i] == '#')turn=2;
			if(map[jc][i] == '1' ){
				map[jc][i] == '2';
				gameover();
			}
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x57)){
            int jc = j-1;
            if(map[jc][i] == '_'){
                map[j][i] = '_'; 
                j--;
                map[j][i] = '2';
                turn=1;
            }if(map[jc][i] == '@'&&map[jc-1][i] == '_'){
                map[j][i] = '_';
                j--;
                map[j][i] = '2';
                map[j-1][i] = '@';
                turn=1;
            }
            if(map[jc][i] == ' ' or map[jc][i] == '#')turn=2;
			if(map[jc][i] == '1' ){
				map[jc][i] == '2';
				gameover();
			}
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x44)){
            int ic = i+2;
            if(map[j][ic] == '_'){
                map[j][i] = '_'; 
                i+=2;
                map[j][i] = '2';
                turn=1;
            }if(map[j][ic] == '@'&&map[j][ic+2] == '_'){
                map[j][i] = '_';
                i+=2;
                map[j][i] = '2';
                map[j][i+2] = '@';
                turn=1;
            }
            if(map[j][ic] == ' ' or map[j][ic] == '#')turn=2;
			if(map[j][ic] == '1' ){
				map[j][ic] == '2';
				gameover();
			}
            Sleep(200);
            return;
        }
        if(GetAsyncKeyState(0x41)){
            int ic = i-2;
            if(map[j][ic] == '_'){
                map[j][i] = '_'; 
                i-=2;
                map[j][i] = '2';
                turn=1;
            }if(map[j][ic] == '@'&&map[j][ic-2] == '_'){
                map[j][i] = '_';
                i-=2;
                map[j][i] = '2';
                map[j][i-2] = '@';
                turn=1;
            }
            if(map[j][ic] == ' ' or map[j][ic] == '#')turn=2;
			if(map[j][ic] == '1' ){
				map[j][ic] == '2';
				gameover();
			}
            Sleep(200);
            return;
        }
    
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
	space(52,6); text = "|   How to play | \n ";
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
	space(50,15); text = "Press any key to go back to menu \n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	getch();
}

void gameover(){
    system("cls");

    int randomcolor;
	srand(time(0));
	int a[randomcolor] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int len = 0,x;
    string text;
	len = text.length();
	cout<<endl;

	space(50,5); text = "\t\t--------------------------\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	space(50,6); text = "\t\t-------- Game Over -------\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	space(50,7); text = "\t\t--------------------------\n\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	space(50,9); text = "\t\t survival you are very noob\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	space(50,10); text = "\t\t Go away Now!\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	space(50,12); text = "\t\tPress any key to go back to menu.";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	getch();
    P1=0;
    P2=0;turn = 0;
	menu();
	}


void gamestart(){
    game_runner = true;
     play1.pts = 0;
     play2.pts = 0;
    if(maptemp==1) maxpts = 2;
    if(maptemp==2) maxpts = 2;
    if(maptemp==3) maxpts = 2;
    if(maptemp==4) maxpts = 2;
    if(maptemp==5) maxpts = 2;

    for(int r=0;r<10;r++){
        for(int c=0;c<60;c++){
    if(maptemp==1) map[r][c] = mapset1[r][c];
    if(maptemp==2) map[r][c] = mapset2[r][c];
    if(maptemp==3) map[r][c] = mapset3[r][c];
    if(maptemp==4) map[r][c] = mapset4[r][c];
    if(maptemp==5) map[r][c] = mapset5[r][c];
    }
    }
    for(int r=0;r<10;r++){
        for(int c=0;c<60;c++){
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
    gotoxy(51,3);
    cout << " |  Level " << maptemp << "  | \n"; 
        for(int dp=0;dp<10;dp++){
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
    if(turn==1&&P1==1) {
        cout << " |    Your score is "<<play1.pts<<"/"<<maxpts<<"  | \n";
        gotoxy(45,13); 
        cout<<" -------------------------- \n"; }
    else if(turn==2&&P2==1) {
        cout << " |    Your score is "<<play2.pts<<"/"<<maxpts<<"  | \n";
        gotoxy(45,13); 
        cout<<" -------------------------- \n";}
    else {
    gotoxy(45,12); 
    cout<<" -------------------------- \n";
    }
    if(P1==1&&play1.pts==maxpts){
        maptemp++;
        gamestart();
    }
    if(P2==1&&play2.pts==maxpts){
        maptemp++;
        gamestart();
    }
    system("pause>nul");
            p1();
            p2();
    }
    }

void menu(){
do{
int randomcolor;
int len = 0,x;
string text;
len = text.length();
system("cls");
SetConsoleTextAttribute(h,6);
space(50,5); text = " -------------------------- \n";
len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

space(50,6); text = " |      LostHope Game     | \n";
len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
space(50,7); text = " --------------------------\n";
len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
SetConsoleTextAttribute(h,14);
space(50,9);  text = "  1. Start Game \n";
len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
space(50,10); text = "  2. How to play  \n";	 
len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
space(50,11); text = "  3. Quit\n";
len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
space(50,13); text = "Select option: ";
len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
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
    int randomcolor;
	srand(time(0));
	int len = 0,x;
    string text;
	len = text.length();
    system("cls");
	SetConsoleTextAttribute(h,4);
	space(50,5); text = " --------------------------- \n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	space(50,6); text = " |     choose role P1      | \n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	space(50,7);text = " ---------------------------\n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
    space(50,9);  text = "1. Survival \n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
    space(50,10); text = "2. Finder \n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
    space(50,11); text = "3. Quit \n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
    space(50,13); text = "Select option: ";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%7+9;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
        SetConsoleTextAttribute(h,6);
    }
        char option = getche();
        if( option=='1') P1=1;
        else if( option=='2') P1=2;
        else if( option=='3') menu();
    }
    system("cls");
	space(50,5); cout << " -------------------------- \n"; 
	space(50,6); if(P1 == 1)cout << " |   P2 role is Finder  |\n";
	else cout << " |   P2 role is Survival|\n"; 
	space(50,7); cout<<" --------------------------\n";
    if( P1 ==1) P2=2;
	else if( P1 ==2) P2=1;

	if( P1 ==1) turn =1;
	else if( P2 == 1 ) turn=2;
    space(52,8);
	cout << "Press any key to START";
	char option = getche();
    
    gamestart();
    
}
/* 
-เดินกิน -> 
-func เปลี่ยนด่าน
หลัง11
-item
-นับก้าว 
*/
