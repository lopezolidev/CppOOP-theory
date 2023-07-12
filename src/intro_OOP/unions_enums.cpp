#include <iostream>

using namespace std;

int main(){
    union num_letter {
        int number;
        char letter;
    };
 
    num_letter value = {'A'}; //values are assigned like a list
 
    cout << "num_letter value.letter: " <<  value.letter << endl; // A
    cout << "num_letter value.number: " <<  value.number << endl; // 65
    cout << "num_letter (char) value.number: " << (char)value.number << endl; // A
    cout << "num_letter (int) value.letter: " << (int)value.letter << endl; // 65

    cout << "num_letter &value: " << &value << endl;
    cout << "num_letter &value.number: " << &value.number << endl; //they both have the same memory address
    cout << "num_letter &value.letter: " << &value.letter << endl;

    enum days_of_week {
        monday = 'm', 
        tuesday = 't',
        wednesday = 'w', 
        thursday = 'h', 
        friday = 'f'}; //listing some values, but from all of them, the variable only will be 1

    days_of_week day = monday;
    cout << "monday (as a number): " << monday << endl;
    cout << "monday (as a character): " << (char)monday << endl;

    return 0;
}