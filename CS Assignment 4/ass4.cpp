// Name        : ass4.cpp
// Author      : Giovanni Parati
// Date           : 11/6/2020
// Description : main method, provided by Zi Li and modified

#include <string>
#include <iostream>
#include "SLLString.h"
using namespace std;

int main(){
    SLLString str("Hello world!");
    SLLString newStr;// = new SLLString;
    newStr = str;
    newStr += SLLString(" CS@BC");
    newStr[6] = 'W';
    cout << newStr << endl; // Hello World! CS@BC
    cout << newStr.length() << endl; //18
    int loc = newStr.findSubstring(SLLString("World"));//newStr.findSubstring("World");
    cout << loc << endl; // 6
    newStr.erase('l'); //erase the letter l.
    cout << newStr << endl; // Heo Word! CS@BC
    newStr.erase('C');
    cout << newStr << endl; // Heo Word! S@B
}
