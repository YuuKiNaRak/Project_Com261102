#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int LV1[50]={1,2,4,1,1,1,2,2,1,1,2,1,2,2,2,2,2,2,2,1,2,2,2,2,2,1,2,2,1,1,2,5,2,1,2,1,3,2,1,1,2,2,2,1,2,2,1,2,2,1}; 
int LV2[50]={2,2,2,3,1,2,1,2,2,2,2,1,1,2,1,2,2,2,1,2,2,1,1,2,1,2,1,2,1,2,2,2,2,2,2,2,2,2,1,1,4,1,3,1,2,1,1,2,2,5};
int LV3[50]={4,2,1,3,1,2,2,2,2,2,2,2,2,2,2,2,1,2,1,2,2,1,2,1,2,1,2,2,1,2,2,1,2,1,2,1,2,2,1,2,1,3,2,2,2,2,3,2,1,5};
int LV4[50]={4,1,2,2,2,1,3,1,2,2,2,1,2,1,2,2,2,2,2,1,2,1,2,1,2,1,1,1,2,2,2,1,2,1,2,2,2,2,2,1,2,2,2,1,2,1,3,1,2,5};
int LV5[50]={4,2,2,1,2,1,2,2,2,1,2,1,2,1,2,1,2,1,1,5,2,2,2,1,3,2,2,2,1,2,2,1,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1};
int LV6[50]={1,1,1,1,1,1,2,2,2,2,4,2,2,2,1,2,1,1,2,2,1,5,2,3,2,1,1,1,1,2,2,2,2,1,1,2,2,2,2,1,1,1,1,1,1,2,2,1,2,1};
int set[50]={};
/*ถ้าจะทำให้int LV_เวลใหม่ ทำแบบLV1
(1) คือ สิ่งกีดขวาง (2) คือ ช่องเดิน (3) คือ ของที่ต้องหา (4) คือ P1 (5) คือ P2
*/
int P1=1;
int P2=2;
int movep1=0;
int movep2=0;
int p1turn=0;//0รอ 1กำลังเดิน 
int p2turn=0;//0รอ 1กำลังเดิน 
int who=0;

void walkp1();
void wakp2();
void checkmap(int lastmove,int who);


int main(){
    p1turn = 1;
	for (int i = 0; i < 50; i++)
	{
		set[i]=LV1[i];
	}    
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
    /////////////////////////////////////
	cout<<" -------------------------- \n";
	if(p1turn == 1)cout<<" |  Use WASD to move P1   | \n"; 
	if(p2turn == 1) cout<<" |  Use WASD to move P2   | \n";
	cout<<" |     Use WASD to move   | \n"; 
	cout<<" --------------------------\n";
    //cout<<"5. Quit(get passcodelevel) *not ready to use now*\n";
    cout << p1turn << " " << movep1 << " \n";
    cout << p2turn << " " << movep2 << " \n";
    cout << lastmove << " \n";
	cout<<"Select option: ";
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
