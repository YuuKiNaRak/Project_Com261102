#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int P1=0;
int P2=0;
int movep1=0;
int movep2=0;
int LV1[50]={1,2,2,1,1,1,2,2,1,1,2,1,2,2,2,2,2,2,2,1,2,2,2,1,2,1,2,2,1,1,1,2,1,1,2,1,3,2,1,1,2,2,2,1,2,2,1,2,2,1}; 
int set[50]={};

void setmap();
void Howtoplay();
void checkmap();
void passcode();//เดะค่อยมาทำ
void space();//จัดหน้า อันนี้มึงทำเจดจัดให้งามๆกลางจอ

int main(){
int ST=0;
do{
system("cls");
cout<<" -------------------------- \n"; 
cout<<" |      LostHope Game     | \n"; 
cout<<" --------------------------\n";
cout<<"     1. Start Game\n";
cout<<"     2. How to play\n";	 
cout<<"     3. Quit\n";
cout<<"Select option: ";
char option = getche();
if( option=='1') ST +=1;
else if( option=='2') Howtoplay();
else if( option=='3') break;	
}
while(ST == 0);
if(ST == 0){}
else{
    do{
    system("cls");
	cout<<" --------------------------- \n"; 
	cout<<" |     choose role P1      | \n"; 
	cout<<" ---------------------------\n";
	if( P1==0){
	cout<<"1. survival \n";
	cout<<"2. Finder \n";
	cout<<"3. Quit \n";
	cout<<"Select option: ";
	char option = getche();
		
	if( option=='1') P1=1;
	else if( option=='2') P1=2;
	else if( option=='3') break;	
	}
	}
    while(P1 == 0 and P2 ==0);
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
	cout<<" |     Use WASD to move   | \n"; 
	cout<<" --------------------------\n";
	cout<<"1. W(up) ";
	cout<<"         2. S(Down) \n";
	cout<<"3. A(lelf) ";
	cout<<"       4. D(right) \n";
    cout<<"5. Quit(get passcodelevel)\n";
	cout<<"Select option: ";
	char option = getche();

	/*if( option=='1') checkmap();
	else if( option=='2') checkmap();
    else if( option=='3') checkmap();
    else if( option=='4') checkmap();
    else if( option=='5') passcode;*/
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
