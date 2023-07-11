#include <iostream>
#include <string>

using namespace std;

struct Person
{
    string name;
    int age;
}; //creating a struct data type, this case 'Person'


int main(){
    Person p; //initializing variable of Person type
    p.name = "Sergio";
    p.age = 25;

    cout << "natural struct: " << endl;
    cout << "name of p is: " << p.name << endl << "age of p is: " << p.age << endl;
    cout << endl;

    Person p2 = Person(); //initializing variable of Person type with a space in memory dedicated to Person, thereby allocating a space of string name and int age during compilling time, i.e: since the beginning
    p2.name = "Xavier";
    p2.age = 32;

    cout << "Struct with method: " << endl;
    cout << "Name of p2 is: " << p2.name << endl << "age of p2 is: " << p2.age << endl;
    cout << endl;

    Person *p3 = new Person(); //creating a pointer for allocating memory space for future use. The pointer *p3 will store only memory addresses of string name and int age, but the actual 'Person' will exist in execution time, therefore being in Heap memory and locating enough memory slots as for the data types it contains

    p3->name = "Jacky"; //pointing to a string value of name but storing memory address of such data
    p3->age = 23;

    cout << "Struct with pointers: " << endl;
    cout << "Name of p3 is: " << p3->name << endl << "age of p3: " << p3->age << endl;
    cout << endl;


    cout << "&p3: " << &p3 << endl;
    cout << "&p3->name: " << &p3->name << endl;
    cout << "sizeof p3: " << sizeof(p3) << endl;

    cout << "sizeof p3->name: " << sizeof(p3->name) << endl;
    cout << "sizeof &p3->name: " << sizeof(&p3->name) << endl;

    cout << "sizeof p3->age: " << sizeof(p3->age) << endl;
    cout << "sizeof &p3->age: " << sizeof(&p3->age) << endl;

    cout << "sizeof Person: " << sizeof(Person) << endl; 

    return 0;
}