#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

int LV1[50]={1,2,2,1,1,1,2,2,1,1,2,1,2,2,2,2,2,2,2,1,2,2,2,1,2,1,2,2,1,1,1,2,1,1,2,1,3,2,1,1,2,2,2,1,2,2,1,2,2,1}; 
int set[50]={};
/*ถ้าจะทำให้int LV_เวลใหม่ ทำแบบLV1
(1) คือ สิ่งกีดขวาง (2) คือ ช่องเดิน (3) คือ ของที่ต้องหา (4) คือ P1 (5) คือ P2
*/
int main(){
    //ข้างล่างคือโค้ดทำแมพขนาด5x10
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
}
