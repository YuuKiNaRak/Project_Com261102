#include <conio.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);



int main()
{   
    int y;
    srand(time(0));
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int a[y] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int len = 0, x;

    string text = "Hello World. I feel pretty today!";
    len = text.length();
    cout << endl << endl << endl << "\t\t";
    for ( x=0;x<len;x++)
    {   y = rand()%15;
        SetConsoleTextAttribute(h, y);
        cout << text[x];
        Sleep(250); 
    }
}
 

