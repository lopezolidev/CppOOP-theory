#include <iostream>
#include <string>

using namespace std;

int main(){
    char text[] = "hello"; //this is a form to write a string using char

    char text_2[] = {'h', 'e', 'l', 'l', 'o', '\0'}; //"correct" form to write a string (internally how C++ treats strings) - \0 indicates where the array finishes

    char *text3 = (char *)"hello"; //equivalent way to write a string using pointers

    cout << "text[] " << text << endl; //string in form of "char"
    cout << "text2[] " << text_2 << endl; //string in form of array
    cout << "*text3 " << text3 << endl; //string in form of pointer
    
    return 0;
}