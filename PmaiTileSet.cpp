#include <iostream>
#include <conio.h>
#include <string>
#include "windows.h"
#include <dos.h>
#include <time.h> 
#include<ctime>

using namespace std;
void P1mv();
//map layout
char map[10][200] = {
"#######",
"###*###",
"##   ##",
"#@@ @@#",
"# @@@ #",
"#@   @#",
"# @@@ #",
"#@ @ @#",
"#  O  #",
"#######",
};

int x=3;
int y=8;//spawnpoint for player
//gamerunning condition
bool game_runner;

int main(){
    //add interface and game menu here <----
    game_runner = true;
    int count = 19;
    char ch;
    //draw map
    while(game_runner == true){
    system("cls");
        for(int dp=0;dp<10;dp++){
            cout << map[dp] << endl;
        }
    system("pause>nul");//for exicute the shattering eff.
    //controll and block interaction
        if(GetAsyncKeyState(VK_DOWN)){
            int yc = y+1;
            if(map[yc][x] == ' '){
                map[y][x] = ' '; 
                y++;
                map[y][x] = 'O';
                count--;
            }if(map[yc][x] == '*'){
                cout << "GG YOU WIN EZ GAME\n";
                game_runner = false;
            }if(map[yc][x] == '@'&&map[yc+1][x] == ' '){
                map[y][x] = ' ';
                y++;
                map[y][x] = 'O';
                map[y+1][x] = '@';
                count--;
            }if(count == 0){
                game_runner = false;
                cout << "GAME OVER\n";
            }
        }
        if(GetAsyncKeyState(VK_UP)){
            int yc = y-1;
            if(map[yc][x] == ' '){
                map[y][x] = ' '; 
                y--;
                map[y][x] = 'O';
                count--;
            }if(map[yc][x] == '*'){
                cout << "GG YOU WIN EZ GAME\n";
                game_runner = false;
            }if(map[yc][x] == '@'&&map[yc-1][x] == ' '){
                map[y][x] = ' ';
                y--;
                map[y][x] = 'O';
                map[y-1][x] = '@';
                count--;
            }if(count == 0){
                game_runner = false;
                cout << "GAME OVER\n";
            }
        }
        if(GetAsyncKeyState(VK_RIGHT)){
            int xc = x+1;
            if(map[y][xc] == ' '){
                map[y][x] = ' '; 
                x++;
                map[y][x] = 'O';
                count--;
            }if(map[y][xc] == '*'){
                cout << "GG YOU WIN EZ GAME\n";
                game_runner = false;
            }if(map[y][xc] == '@'&&map[y][xc+1] == ' '){
                map[y][x] = ' ';
                x++;
                map[y][x] = 'O';
                map[y][x+1] = '@';
                count--;
            }if(count == 0){
                game_runner = false;
                cout << "GAME OVER\n";
            }
        }
        if(GetAsyncKeyState(VK_LEFT)){
            int xc = x-1;
            if(map[y][xc] == ' '){
                map[y][x] = ' '; 
                x--;
                map[y][x] = 'O';
                count--;
            }if(map[y][xc] == '*'){
                cout << "GG YOU WIN EZ GAME\n";
                game_runner = false;
            }if(map[y][xc] == '@'&&map[y][xc-1] == ' '){
                map[y][x] = ' ';
                x--;
                map[y][x] = 'O';
                map[y][x-1] = '@';
                count--;
            }if(count == 0){
                game_runner = false;
                cout << "GAME OVER\n";
            }
        }
    }
    return 0;
}

