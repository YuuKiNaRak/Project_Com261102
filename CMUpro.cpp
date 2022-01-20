
//รับข้อมูลลูกศร
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

#define key_up 72
#define key_down 80
#define key_left 75
#define key_right 77

void map1(){
	string map[]={"#####","#"};
	for(int i=0; i<10; i++){
		cout << map[0] ;
    }
    cout << "\n";
    for(int i=0; i<14; i++){
        cout << map[1] << "                                                " << map[1] << "\n" ;
    }
    for(int i=0; i<10; i++){
		cout << map[0] ;
    }
	
}

void map2(){
	string map[]={"#####","#"};
}

void walkP1P2(){
    char key = getch(); //getch( )  คือ ฟังก์ชันที่ใช้รับข้อมูลเพียง  1  ตัวอักขระจากคีย์บอร์ด
	int value = key;

	while(1){
		switch (getch())
		{
		case key_up:
		cout << "Up arrow";
			break;
		
		case key_down:
		cout << "Down arrow";
		break;

		case key_right:
		cout << "right arrow";
		break;
		
		case key_left:
		cout << "Left arrow";
		break;

		case 1:
		cout << "";
		break;

		default:
			break;
		}
	
}
}

void roleP2(int &P1){
    do{
    system("cls");
	cout<<" -------------------------- \n"; 
	cout<<" |   Your role is" ;
	if(P1 == 1)cout << " Finder  |\n";
	else cout << " Survival|\n"; 
	cout<<" --------------------------\n";
	cout<<"1. Next \n";
	cout<<"2. Quit \n";
	cout<<"Select option: ";
	char option = getche();
	if( option=='1') break;
	else if( option=='2') break;
	}
    while(1);
}

void chooseroleP1(){
    do{
    system("cls");
	cout<<" --------------------------- \n"; 
	cout<<" |     choose role P1      | \n"; 
	cout<<" ---------------------------\n";
	if( P1==0){
	cout<<"1. survival \n";
	cout<<"2. Finder \n";
	cout<<"3. back \n";
	cout<<"Select option: ";
	char option = getche();
		
	if( option=='1') P1=1;
	else if( option=='2') P1=2;
	else if( option=='3') return;	
	}
	if( P1==1){
	system("cls");
	cout<<" --------------------------- \n"; 
	cout<<" | Select Survival SureP1? | \n"; 
	cout<<" ---------------------------\n";
	cout<<"1. Yes \n";	 
	cout<<"2. No \n";
	cout<<"Select option: ";
	char option = getche();
		
	if( option=='1') roleP2(P1);
	else if( option=='2') P1=0;		
	}
	if( P1==2){
	system("cls");
	cout<<" --------------------------- \n"; 
	cout<<" |  Select Finder SureP1?  | \n"; 
	cout<<" ---------------------------\n";
	cout<<"1. Yes \n";	 
	cout<<"2. No \n";
	cout<<"Select option: ";
	char option = getche();
		
	if( option=='1') roleP2(P1);
	else if( option=='2') P1=0;	
	}
	}
    while(1);
}
void Howtoplay(){
    do{
    system("cls");
	cout<<" -------------------------- \n"; 
	cout<<" |        (How)           | \n"; 
	cout<<" --------------------------\n";
	cout<<"1. Start Game\n";
	cout<<"2. Back\n";	 
	cout<<"Select option: ";
	char option = getche();
		
	if( option=='1') chooseplayer();
	else if( option=='2') return;
	else ;	
    }
    while(1);
}

int main(){
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
		
	if( option=='1') chooseplayer();
	else if( option=='2') Howtoplay();
	else if( option=='3') break;	
    }
    while(1);
return 0;

}
/////////////////////////////////////////
