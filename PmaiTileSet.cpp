#include <iostream>
#include <conio.h>
#include <string>
#include "windows.h"
#include <dos.h>
#include <time.h> 

using namespace std;
void P1mv();
char map[10][200] = {
"####################################################################################################",
"#O    @                                                                                            #",
"#                                                                                                  #",
"#                                                                                                  #",
"#            @                                                                                     #",
"#                                                                               *                  #",
"#                                                                                                  #",
"#                                                                                                  #",
"#                                                                                                  #",
"####################################################################################################",
};

int x=1;
int y=1;//spawnpoint

bool game_runner = true;

int main(){
    
    while(game_runner == true){
    system("cls");
        for(int dp=0;dp<10;dp++){
            cout << map[dp] << endl;
        }
    system("pause>nul");
        if(GetAsyncKeyState(VK_DOWN)){
            int yc = y+1;
            if(map[yc][x] == ' '){
                map[y][x] = ' '; 
                y++;
                map[y][x] = 'O';
            }if(map[yc][x] == '*'){
                map[y][x] = ' '; 
                cout << "GG YOU WIN EZ GAME";
                game_runner = false;
            }if(map[yc][x] == '@'&&map[yc+1][x] == ' '){
                map[y][x] = ' ';
                y++;
                map[y][x] = 'O';
                map[y+1][x] = '@';
            }
        }
        if(GetAsyncKeyState(VK_UP)){
            int yc = y-1;
            if(map[yc][x] == ' '){
                map[y][x] = ' '; 
                y--;
                map[y][x] = 'O';
            }if(map[yc][x] == '*'){
                map[y][x] = ' '; 
                cout << "GG YOU WIN EZ GAME";
                game_runner = false;
            }if(map[yc][x] == '@'&&map[yc-1][x] == ' '){
                map[y][x] = ' ';
                y--;
                map[y][x] = 'O';
                map[y-1][x] = '@';
            }
        }
        if(GetAsyncKeyState(VK_RIGHT)){
            int xc = x+1;
            if(map[y][xc] == ' '){
                map[y][x] = ' '; 
                x++;
                map[y][x] = 'O';
            }if(map[y][xc] == '*'){
                map[y][x] = ' '; 
                cout << "GG YOU WIN EZ GAME";
                game_runner = false;
            }if(map[y][xc] == '@'&&map[y][xc+1] == ' '){
                map[y][x] = ' ';
                x++;
                map[y][x] = 'O';
                map[y][x+1] = '@';
            }
        }
        if(GetAsyncKeyState(VK_LEFT)){
            int xc = x-1;
            if(map[y][xc] == ' '){
                map[y][x] = ' '; 
                x--;
                map[y][x] = 'O';
            }if(map[y][xc] == '*'){
                map[y][x] = ' '; 
                cout << "GG YOU WIN EZ GAME";
                game_runner = false;
            }if(map[y][xc] == '@'&&map[y][xc-1] == ' '){
                map[y][x] = ' ';
                x--;
                map[y][x] = 'O';
                map[y][x-1] = '@';
            }
        }
    }
    
    return 0;
}


