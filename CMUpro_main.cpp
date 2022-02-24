#include"touchup.h"
#define STD_OUTPUT_HANDLE ((DWORD)-11)

using namespace std;
class point{
public:
    int pts;
};
void p1();
void p2();
void gamestart();
void gameover();
void menu();
void role();
void nextmap();

char mapset1[10][60] = {
"_ _ _ \3 # _ # _ _ 2",  
"_ # # _ _ _ _ _ # _",    
"_ # # _ # _ # _ # _",  
"_ _ _ # \3 # \3 _ # #",    
"_ _ _ _ _ _ _ _ # #",
"1 # \3 # _ # # _ _ _"};
char mapset2[10][60] = {
"_ _ _ 1 _ _ _",
"_ # _ \3 _ # _",
"_ # _ _ _ # _",
"_ _ _ \4 _ _ _",
"\3 _ @ _ @ _ \3",
"_ _ _ \4 _ _ _",
"_ # _ _ _ # _",
"_ # _ \3 _ # _",
"_ _ _ 2 _ _ _"};
char mapset3[10][60] = {
"# _ _ \4 _ # _ _ _ # _ _ _",
"_ # _ _ _ _ _ \3 _ # _ \4 _",
"_ _ _ _ _ # _ _ _ \3 _ _ _",
"_ # _ _ _ # _ _ # _ # _ _",
"# _ # \4 # _ _ _ # _ # _ _",
"# _ _ _ _ _ \4 _ _ _ 2 _ \4",
"_ # _ # _ # _ _ _ _ # _ _",
"1 \3 _ _ _ \4 _ _ _ # _ _ _",
"_ _ _ # _ _ \4 _ _ _ _ _ _",
"_ # _ _ _ # _ _ _ # \3 _ #"};
char mapset4[10][60] = {
"# _ _ _ 1 _ _ # _ _ _ # _ \3 _",
"_ _ # _ _ _ _ # _ _ _ # _ _ _",
"_ _ # _ _ _ _ # _ _ _ \3 _ _ _",
"_ _ _ # \3 # _ # _ _ _ _ # _ _",
"_ _ _ # \4 # _ \4 _ _ _ _ # _ _",
"_ _ _ # _ _ \4 _ \4 _ _ _ 2 _ \4",
"_ _ _ # _ # # # _ _ _ _ # _ _",
"_ _ \3 \4 _ _ _ \4 _ _ _ _ _ _ _",
"_ _ _ _ # _ _ # _ _ _ _ _ _ _",
"_ _ _ _ _ _ _ # _ _ _ # \3 _ #"};
char mapset5[10][60] = {
"1 \4 _ _ _ _ _ _ \4 _ _ _ _ _ _ \3 #",
"\4 \3 _ # # # # _ _ _ # # # # _ \4 _",
"_ _ # _ # _ _ _ \4 _ _ _ # _ # _ _",
"_ _ _ _ \4 _ _ # _ # _ _ \4 _ _ _ _",
"_ @ _ \3 # _ \4 _ \3 _ \4 _ # \3 _ @ _",
"_ _ _ _ \4 _ _ # _ # _ _ \4 _ _ _ _",
"_ _ # _ # _ _ _ \4 _ _ _ # _ # _ _",
"_ \4 _ # # # # _ _ _ # # # # _ \3 \4",
"\3 _ _ _ _ _ _ _ \4 _ _ _ _ _ _ \4 2"};

char map[10][60];
int x,y,i,j;
int times=60;
//spawnpoint
int turn=0,P1=0,P2=0;//determide turn and role 1=sur 2=finder
bool game_runner = false;
point play1;
point play2;
int maxpts;
int maptemp=1;//เลเวลด่าน
int yspace;//สำหรับแมพยาว
int xspace;//สำหรับแมพกว้าง
int wintype=0;//ใครชนะในroleไหน
int main(){
srand(time(0));
opening();
menu();
exit; 
}
void p1(){
    //condition สำหรับ P1 เมื่อเป็น Sur
      if(turn==1&&P1==1){
        if(GetAsyncKeyState(0x53)){
            int yc = y+1;
            if(map[yc][x] == '_'){
                map[y][x] = '_'; 
                y++;
                map[y][x] = '1';
                turn=2;
            }if(map[yc][x] == '\3'){
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
            }if(map[yc][x] == '\4'&&map[yc+1][x] == '_'){
                map[y][x] = '_';
                y++;
                map[y][x] = '@';
                y++;
                map[y][x] = '1';
                turn=2;
            }
            if(map[yc][x] == ' ' or map[yc][x] == '#')turn=1;
            if(map[yc][x] == '2'){
                wintype=4;
			    map[y][x] = 'X';
                Sleep(500);
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

            }if(map[yc][x] == '\3'){
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
            }if(map[yc][x] == '\4'&&map[yc-1][x] == '_'){
                map[y][x] = '_';
                y--;
                map[y][x] = '@';
                y--;
                map[y][x] = '1';
                turn=2;
            }

            if(map[yc][x] == '2'){
                wintype=4;
			    map[y][x] = 'X';
                Sleep(500);
				gameover();
			}
            if(map[yc][x] == ' ' or map[yc][x] == '#')turn=1;
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
            }if(map[y][xc] == '\3'){
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
            }if(map[y][xc] == '\4'&&map[y][xc+2] == '_'){
                map[y][x] = '_';
                x+=2;
                map[y][x] = '@';
                x+=2;
                map[y][x] = '1';
                turn=2;
            }

            if(map[y][xc] == ' ' or map[y][xc] == '#')turn=1;
			if(map[y][xc] == '2'){
                wintype=4;
			    map[y][x] = 'X';
                Sleep(500);
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
                }if(map[y][xc] == '\3'){
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

            }if(map[y][xc] == '\4'&&map[y][xc-2] == '_'){
                map[y][x] = '_';
                x-=2;
                map[y][x] = '@';
                x-=2;
                map[y][x] = '1';
                turn=2;
            }
            if(map[y][xc] == ' ' or map[y][xc] == '#')turn=1;
			if(map[y][xc] == '2'){
                wintype=4;
			    map[y][x] = 'X';
                Sleep(500);
				gameover();
			}
            Sleep(200);
            return;
        }
    }
     //condition สำหรับ P1 เมื่อเป็น Fin
    if(turn==1&&P1==2){
        if(GetAsyncKeyState(0x53)){
            int yc = y+1;
            if(map[yc][x] == '_'){
                map[y][x] = '_'; 
                y++;
                map[y][x] = '1';
                turn=2;
            }if(map[yc][x] == '@'){
                map[y][x] = '_';
                y++;
                map[y][x] = '1';
                turn=2;
            }if(map[yc][x] == '\3'&&map[yc+1][x] == '_'){
                map[y][x] = '_';
                y++;
                map[y][x] = '1';
                map[y+1][x] = '\3';
                turn=2;
            }if(map[yc][x] == '\4'&&map[yc+1][x] == '_'){
                map[y][x] = '_';
                y++;
                map[y][x] = '@';
                y++;
                map[y][x] = '1';
                turn=2;
            }
            if(map[yc][x] == ' ' or map[yc][x] == '#')turn=1;
			if(map[yc][x] == '2'){
                wintype=3;
				map[yc][x] = 'X';
                Sleep(500);
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
            }if(map[yc][x] == '@'){
                map[y][x] = '_';
                y--;
                map[y][x] = '1';
                turn=2;
            }if(map[yc][x] == '\3'&&map[yc-1][x] == '_'){
                map[y][x] = '_';
                y--;
                map[y][x] = '1';
                map[y-1][x] = '\3';
                turn=2;
            }if(map[yc][x] == '\4'&&map[yc-1][x] == '_'){
                map[y][x] = '_';
                y--;
                map[y][x] = '@';
                y--;
                map[y][x] = '1';
                turn=2;
            }
            if(map[yc][x] == ' ' or map[yc][x] == '#')turn=1;
			if(map[yc][x] == '2'){
			    map[yc][x] = 'X';
                wintype=3;
                Sleep(500);
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
            }if(map[y][xc] == '@'){
                map[y][x] = '_';
                x+=2;
                map[y][x] = '1';
                turn=2;
             }if(map[y][xc] == '\3'&&map[y][xc+2] == '_'){
                map[y][x] = '_';
                x+=2;
                map[y][x] = '1';
                map[y][x+2] = '\3';
                turn=2;
            }if(map[y][xc] == '\4'&&map[y][xc+2] == '_'){
                map[y][x] = '_';
                x+=2;
                map[y][x] = '@';
                x+=2;
                map[y][x] = '1';
                turn=2;
            }
            if(map[y][xc] == ' ' or map[y][xc] == '#')turn=1;
			if(map[y][xc] == '2'){
				map[y][xc] = 'X';
                wintype=3;
                Sleep(500);
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
            }if(map[y][xc] == '@'){
                map[y][x] = '_';
                x-=2;
                map[y][x] = '1';
                turn=2;
            }if(map[y][xc] == '\3'&&map[y][xc-2] == '_'){
                map[y][x] = '_';
                x-=2;
                map[y][x] = '1';
                map[y][x-2] = '\3';
                turn=2;
            }if(map[y][xc] == '\4'&&map[y][xc-2] == '_'){
                map[y][x] = '_';
                x-=2;
                map[y][x] = '@';
                x-=2;
                map[y][x] = '1';
                turn=2;
            }
            if(map[y][xc] == ' ' or map[y][xc] == '#')turn=1;
			if(map[y][xc] == '2'){
				map[y][xc] = 'X';
                wintype=3;
                Sleep(500);
				gameover();
			}
            Sleep(200);
            return;
        }
    }
}
void p2(){
//condition สำหรับ P2 เมื่อเป็น Sur
if(turn==2&&P2==1){
        if(GetAsyncKeyState(0x53)){
            int jc = j+1;
            if(map[jc][i] == '_'){
                map[j][i] = '_'; 
                j++;
                map[j][i] = '2';
                turn=1;
            }if(map[jc][i] == '\3'){
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
            }if(map[jc][i] == '\4'&&map[jc+1][i] == '_'){
                map[j][i] = '_';
                j++;
                map[j][i] = '@';
                j++;
                map[j][i] = '2';
                turn=1;
            }

            if(map[jc][i] == ' ' or map[jc][i] == '#')turn=2;
			if(map[jc][i] == '1' ){
                wintype=3;
				map[j][i] = 'X';
                Sleep(500);
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
            }if(map[jc][i] == '\3'){
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
            }if(map[jc][i] == '\4'&&map[jc-1][i] == '_'){
                map[j][i] = '_';
                j--;
                map[j][i] = '@';
                j--;
                map[j][i] = '2';
                turn=1;
            }
            if(map[jc][i] == ' ' or map[jc][i] == '#')turn=2;
			if(map[jc][i] == '1' ){
                wintype=3;
			    map[j][i] = 'X';
                Sleep(500);
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
            if(map[j][ic] == '\3'){
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
            }if(map[j][ic] == '\4'&&map[j][ic+2] == '_'){
                map[j][i] = '_';
                i+=2;
                map[j][i] = '@';
                i+=2;
                map[j][i] = '2';
                turn=1;
            }
            if(map[j][ic] == ' ' or map[j][ic] == '#')turn=2;
			if(map[j][ic] == '1' ){
                wintype=3;
			    map[j][i] = 'X';
                Sleep(500);
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
            }if(map[j][ic] == '\3'){
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
            }if(map[j][ic] == '\4'&&map[j][ic-2] == '_'){
                map[j][i] = '_';
                i-=2;
                map[j][i] = '@';
                i-=2;
                map[j][i] = '2';
                turn=1;
            }
            if(map[j][ic] == ' ' or map[j][i] == '#')turn=2;
			if(map[j][ic] == '1' ){
                wintype=3;
			    map[j][i] = 'X';
                Sleep(500);
				gameover();
			}
            Sleep(200);
            return;
        }
    
    }
//condition สำหรับ P2 เมื่อเป็น Fin
if(turn==2&&P2==2){
        if(GetAsyncKeyState(0x53)){
            int jc = j+1;
            if(map[jc][i] == '_'){
                map[j][i] = '_'; 
                j++;
                map[j][i] = '2';
                turn=1;
            }if(map[jc][i] == '@'){
                map[j][i] = '_';
                j++;
                map[j][i] = '2';
                turn=1;
            }if(map[jc][i] == '\3'&&map[jc+1][i] == '_'){
                map[j][i] = '_';
                j++;
                map[j][i] = '2';
                map[j+1][i] = '\3';
                turn=1;
            }if(map[jc][i] == '\4'&&map[jc+1][i] == '_'){
                map[j][i] = '_';
                j++;
                map[j][i] = '@';
                j++;
                map[j][i] = '2';
                turn=1;
            }
            if(map[jc][i] == ' ' or map[jc][i] == '#')turn=2;
			if(map[jc][i] == '1' ){
                wintype=4;
			    map[jc][i] = 'X';
                Sleep(500);
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
            }if(map[jc][i] == '@'){
                map[j][i] = '_';
                j--;
                map[j][i] = '2';
                turn=1;
            }if(map[jc][i] == '\3'&&map[jc-1][i] == '_'){
                map[j][i] = '_';
                j--;
                map[j][i] = '2';
                map[j-1][i] = '\3';
                turn=1;
            }if(map[jc][i] == '\4'&&map[jc-1][i] == '_'){
                map[j][i] = '_';
                j--;
                map[j][i] = '@';
                j--;
                map[j][i] = '2';
                turn=1;
            }
            if(map[jc][i] == ' ' or map[jc][i] == '#')turn=2;
			if(map[jc][i] == '1' ){
                wintype=4;
			    map[j][i] = 'X';
                Sleep(500);
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
            }if(map[j][ic] == '@'){
                map[j][i] = '_';
                i+=2;
                map[j][i] = '2';
                turn=1;
            }if(map[j][ic] == '\3'&&map[j][ic+2] == '_'){
                map[j][i] = '_';
                i+=2;
                map[j][i] = '2';
                map[j][i+2] = '\3';
                turn=1;
            }if(map[j][ic] == '\4'&&map[j][ic+2] == '_'){
                map[j][i] = '_';
                i+=2;
                map[j][i] = '@';
                i+=2;
                map[j][i] = '2';
                turn=1;
            }
            if(map[j][ic] == ' ' or map[j][ic] == '#')turn=2;
			if(map[j][ic] == '1' ){
                wintype=4;
			    map[j][ic] = 'X';
                Sleep(500);
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
            }if(map[j][ic] == '@'){
                map[j][i] = '_';
                i-=2;
                map[j][i] = '2';
                turn=1;
            }if(map[j][ic] == '\3'&&map[j][ic-2] == '_'){
                map[j][i] = '_';
                i-=2;
                map[j][i] = '2';
                map[j][i-2] = '\3';
                turn=1;
            }if(map[j][ic] == '\4'&&map[j][ic-2] == '_'){
                map[j][i] = '_';
                i-=2;
                map[j][i] = '@';
                i-=2;
                map[j][i] = '2';
                turn=1;
            }
            if(map[j][ic] == ' ' or map[j][ic] == '#')turn=2;
			if(map[j][ic] == '1' ){
                wintype=4;
			    map[j][ic] = 'X';
                Sleep(500);
				gameover();
			}   
            Sleep(200);
            return;
        }
    
    }
    }
// gameover screen
void gameover(){  
    system("cls");
    if(wintype==1) {
        overscreen();
        Sleep(100);
        p1winassur();
    }
    if(wintype==2) {
        overscreen();
        Sleep(100);
        p1winassur();
    }
    if(wintype==3){
    overscreen();
    Sleep(100);
     p1winasfin();   
    } 
    if(wintype==4) {
        overscreen();
        Sleep(100);
        p2winasfin();
    }
	getch();
    P1=0;
    P2=0;turn = 0;
    maptemp=1;
    game_runner=false;
    overscreen();
    exit;
	}
void gamestart(){
    game_runner = true;
     play1.pts = 0;
     play2.pts = 0;
    if(maptemp==1){
        maxpts = 2;
        yspace=1;
        xspace=0;
    } 
      if(maptemp==2){
        maxpts = 3;
        yspace=5;
        xspace=-3;
    } 
      if(maptemp==3){
        maxpts = 4;
        yspace=5;
        xspace=4;
    } 
      if(maptemp==4){
        maxpts = 5;
        yspace=5;
        xspace=6;
    } 
      if(maptemp==5){
        maxpts = 6;
        yspace=4;
        xspace=8;
    } if(maptemp==6){
        if(P1==1) wintype=1;
        if(P2==1) wintype=2;
        gameover();
    }
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
    gotoxy(52,3);
    cout << " |  Level " << maptemp << "  | \n"; 
        for(int dp=0;dp<10;dp++){
            space(50-xspace,5+dp);
            cout << map[dp]<< endl;
        }
    gotoxy(45,10+yspace); 
    cout<<" -------------------------- \n";
    if(turn==1){gotoxy(45,11+yspace); 
                cout << " |  Use WASD to move P1   | \n"; }
    else {gotoxy(45,11+yspace);  
    cout << " |  Use WASD to move P2   | \n"; }
    gotoxy(45,12+yspace);
    if(turn==1&&P1==1) {
        cout << " |    Your score is "<<play1.pts<<"/"<<maxpts<<"   | \n";
        gotoxy(45,13+yspace); 
        cout<<" -------------------------- \n"; }
    else if(turn==2&&P2==1) {
        cout << " |    Your score is "<<play2.pts<<"/"<<maxpts<<"   | \n";
        gotoxy(45,13+yspace); 
        cout<<" -------------------------- \n";}
    else {
    gotoxy(45,12+yspace); 
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
    if( option=='1') {
        loadingscreen();
        Sleep(10);
        role();
    }
    else if( option=='2') {
        loadingscreen();
        Sleep(10);
        Howtoplay();
    }
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
    space(50,9);  text = "1. Survivor \n";
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
    }
        char option = getche();
        if( option=='1') P1=1;
        else if( option=='2') P1=2;
        else if( option=='3') {
            loadingscreen();
            Sleep(100);
            return;
        }
    }
    loadingscreen();
    SetConsoleTextAttribute(h,11);
	space(50,5); cout << " -------------------------\n"; 
	space(50,6); 
    if(P1 == 1)cout << " |   P2 role is Finder   |\n";
	else {cout << " |  P2 role is Survivor  |\n";} 
	space(50,7); cout<<" -------------------------\n";
    SetConsoleTextAttribute(h,12);
    space(52,8); cout << "_ : A path you can walk";
    space(52,9); cout << "# : A wall";
    space(52,10); cout << "@ : A pushable block";
    space(52,11); cout << "\4 : A skipblock";
    space(52,12); cout << "\3 : A key fragment";
    if( P1 ==1) P2=2;
	else if( P1 ==2) P2=1;

	if( P1 ==1) turn =1;
	else if( P2 == 1 ) turn=2;
    space(52,14);
    SetConsoleTextAttribute(h,14);
	cout << "Press any key to START";
	char option = getche();
    loadingscreen();
    Sleep(100);
    gamestart();
}
