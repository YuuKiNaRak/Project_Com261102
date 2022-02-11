#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <dos.h>
#include <time.h> 

using namespace std;

int x = 0 ;
int y = 0 ;
char P1 = 'E';
char P2 = 'E';
int movep1=0;//เดินตามช่องarray
int movep2=0;//เดินตามช่องarray
char Turn = 'S';
int LV1[50]={1,2,4,1,1,1,2,2,1,1,2,1,2,2,2,2,2,2,2,1,2,2,2,2,2,1,2,2,1,1,2,5,2,1,2,1,3,2,1,1,2,2,2,1,2,2,1,2,2,1};
int LV2[50]={2,2,2,3,1,2,1,2,2,2,2,1,1,2,1,2,2,2,1,2,2,1,1,2,1,2,1,2,1,2,2,2,2,2,2,2,2,2,1,1,4,1,3,1,2,1,1,2,2,5};
int LV3[50]={4,2,1,3,1,2,2,2,2,2,2,2,2,2,2,2,1,2,1,2,2,1,2,1,2,1,2,2,1,2,2,1,2,1,2,1,2,2,1,2,1,3,2,2,2,2,3,2,1,5};
int LV4[50]={4,1,2,2,2,1,3,1,2,2,2,1,2,1,2,2,2,2,2,1,2,1,2,1,2,1,1,1,2,2,2,1,2,1,2,2,2,2,2,1,2,2,2,1,2,1,3,1,2,5};
int LV5[50]={4,2,2,1,2,1,2,2,2,1,2,1,2,1,2,1,2,1,1,5,2,2,2,1,3,2,2,2,1,2,2,1,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1};
int LV6[50]={1,1,1,1,1,1,2,2,2,2,4,2,2,2,1,2,1,1,2,2,1,5,2,3,2,1,1,1,1,2,2,2,2,1,1,2,2,2,2,1,1,1,1,1,1,2,2,1,2,1};
int set[50]={};
int setlevel=0;
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
	int len = 0,x;
    string text;
	len = text.length();
	
	
	
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int ST=0;
do{
system("cls");

	
	space(50,5);
	text = " -------------------------- \n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }


space(50,6); 
 text = " |      LostHope Game     | \n";
len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];
	}


space(50,7); 
text = " -------------------------- \n";
    len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }


space(50,9);
text = "  1. Start Game \n";
len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

  
space(50,10); 
text ="  2. How to play  \n";	
len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

space(50,11);
 text = "  3. Quit\n";
len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

space(50,13);
text = "Select option: ";
len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

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
	
	space(50,5);  
	text = " --------------------------- \n"; 
	len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	space(50,6); text = " |     choose role P1      | \n"; 
	len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	space(50,7); text = " ---------------------------\n";
	len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	if( P1==0){
	space(50,9);  text = "1. Survival \n";
	len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	space(50,10);text = "2. Finder \n";
	len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	space(50,11); text = "3. Quit \n";
	len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	space(50,13); text = "Select option: ";
	len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	char option = getche();
	if( option=='1') P1 = 'S';
	else if( option=='2') P1 = 'F';
	else if( option=='3') break;
	}
	}while(P1 != 'E');
	/////////////////////////////////////
    do{
    system("cls");
	space(50,5); text = " -------------------------- \n"; 
	len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	space(50,6); if(P1 == 'S'){text = " |   P2 role is Finder  |\n";
	len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	}

	else{ text =  " |   P2 role is Survival|\n"; 
	len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	}

	space(50,7); text = " --------------------------\n";
	len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	space(50,9); text = "1. Next \n";
	len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }

	space(50,10);text = "2. Quit \n";
	len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
    }
	
	space(50,13);text = "Select option: ";
	len = text.length();
	for(x=0;x<len;x++){
	    randomcolor = rand()%15;
		SetConsoleTextAttribute(h,randomcolor);
		cout << text[x];	
		SetConsoleTextAttribute(h,6);
    }

	char option = getche();

	if( P1 == 'S') P2 = 'F';
	else if( P1 == 'F') P2 = 'S';

	if( option=='1')setmap();
	else if( option=='2') break;
	}while( P2 != 'E');
}
}


bool walkPY(){
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

    if (movep2 == movep1){
   	system("cls");
	cout<<endl;
	cout<<"\t\t--------------------------"<<endl;
	cout<<"\t\t-------- Game Over -------"<<endl;
	cout<<"\t\t--------------------------"<<endl<<endl;
	cout<<"\t\t P1 you are very noob"<<endl; //ไอสัสมึงพิมใช่ไหมบิววววววววว
	cout<<"\t\t Go away Now!"<<endl;
	cout<<"\t\tPress any key to go back to menu.";
	getch();
	return 0;
	}
    	}
    }
	
    cout << "\n";
	cout << P1 << " " << P2;
	space(50,7); cout<<" -------------------------- \n";
	space(50,8);if(Turn == 'S')cout<<" |  Use WASD to move Survival  | \n"; 
	space(50,8);if(Turn == 'F') cout<<" |  Use WASD to move Finder   | \n"; 
	space(50,10); cout<<" --------------------------\n";
	space(50,15); cout<<"Select option: ";
	char option = getche();
	if(Turn == 'S'){
	if(P1 == 'S'){
	who=1;
	if( option=='w') movep1 -= 10;
	else if( option=='s') movep1 += 10;
	else if( option=='a') movep1 -= 1;
	else if( option=='d') movep1 += 1;
	}
	else{
	who=2;
	if( option=='w') movep2 -= 10;
	else if( option=='s') movep2 += 10;
	else if( option=='a') movep2 -= 1;
	else if( option=='d') movep2 += 1;
	}
		
	}

	if(Turn == 'F'){
	if(P1 == 'F'){
	who=1;
	if( option=='w') movep1 -= 10;
	else if( option=='s') movep1 += 10;
	else if( option=='a') movep1 -= 1;
	else if( option=='d') movep1 += 1;
	}
	else{
	who=2;
	if( option=='w') movep2 -= 10;
	else if( option=='s') movep2 += 10;
	else if( option=='a') movep2 -= 1;
	else if( option=='d') movep2 += 1;
	}
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
	if(setlevel == 0) setlevel=1;
	for (int i = 0; i < 50; i++)
	{
		if(setlevel == 1) set[i]=LV1[i];
		if(setlevel == 2) set[i]=LV2[i];
		if(setlevel == 3) set[i]=LV3[i];
		if(setlevel == 4) set[i]=LV4[i];
		if(setlevel == 5) set[i]=LV5[i];
		if(setlevel == 6) set[i]=LV6[i];
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
        if(Turn == 'F') Turn = 'S';
		if(Turn == 'S') Turn = 'F';
        set[movep1]=4;
        set[movep1-lastmove]=2;
        }
    }
    if(who == 2){
    if(set[movep2] == 1){
    movep2 -= lastmove;
    } 
    else{
        if(Turn == 'F') Turn = 'S';
		if(Turn == 'S') Turn = 'F';
	    set[movep2]=5;
        set[movep2-lastmove]=2;
    }
    }

	//เมื่อmovep1เก็บ*แล้วให้เกิดevenบางอย่างเพื่อเช็คว่ามันสามารถเก็บ*ได้หรือยัง
	int cc,next,jojo = 3;
	for(cc = 0;cc<50;cc++){
		if(jojo == LV1[cc]){
		int next = cc;
		
		if (movep1 == next){
		setlevel +=1;
		setmap();
		} 
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
