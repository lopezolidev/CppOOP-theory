#include <iostream>

using namespace std;

//Testing the difference of pointers to standard variables and checking memory addresses

void change(char *c){ //recieves a character as a pointer
    cout << "character recieved: " << *c << endl;
    *c = 'Q'; //changes the original value of the variable with the pointer
    cout << "current character: " << *c << endl; 
}

int main(){
    char letter = 'A';
    char *pointer = &letter;

    cout << "letter " << letter << endl; 
    //output: letter A
    
    cout << "&letter " << (int *) &letter << endl; //we use (int *) to deal with memory addresses as numbers instead of characters
    //output: &letter 0x7fffe2619c6f
    
    cout << "pointer " << (int *) pointer << endl;
    //output: pointer 0x7fffe2619c6f
    
    //both '&letter' and 'pointer' have the same memory address, therefore confirming what do pointers do

    cout << "*pointer " << *pointer << endl;
    //output: *pointer A
 

    char character = 'B';
    cout << "initial character: " << character << endl;
    change(&character); //passing a variable through refference in this function
    cout << "final character: " << character; //the original variable value results different

    return 0;
}