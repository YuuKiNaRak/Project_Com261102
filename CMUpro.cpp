
//รับข้อมูลลูกศร
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

#define key_up 72
#define key_down 80
#define key_left 75
#define key_right 77


int main(){
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


		default:
			break;
		}

	
	
}
return 0;
}
