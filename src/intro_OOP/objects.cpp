#include <iostream>
#include <string>

using namespace std;

class Person {
private: // encapsuling these attributes
// public:  //all attributes and methods from the class will be private by default
    string name;
    int age;
    bool gender;

public:
// constructor method
    static int counter_persons;  //we cannot assign a value directly to counter_persons, instead we must assing it explicitly
    Person(string name, int age, bool gender){
        this->name = name; //assigning the paramenter to the name of the instanced object
        //using pointer 'this' for refering the instance itself
        this->age = age;
        this->gender = gender;
        counter_persons++;
    } //"normal" constructor 

    // Person(string n, int a, bool g) : name(n), age(a), gender(g) {} //"in-line" assignation for attributes of the constructor

// destructor method

    ~Person(){} // no arguments or inner logic because we're not allocating additional memory space

    //using getters
    string getName(){
        return name;
    } 

    int getAge(){
        return age;
    }

    bool getGender(){
        return gender;
    }

    //using setters
    // void setName(string name){
    //     this->name = name;
    // } //"normal" setter

    Person &setName(string name){
        this->name = name;
        return *this;
    } //returning the instance itself. The return type is Person, for returing the data type that the instance is. We call the method with a memory reference

    Person &setAge(int age){
        this->age = age;
        return *this;
    }

    void setGender(bool gender){
        this->gender = gender;
    }



    void greet(); //method to use a variable inside the instanced object → Now 'greet()' is a method defined outside the class
};

int Person::counter_persons = 0; //explicitly defining its value

//we can also define functions outside a class using '::' operator (scope resolution operator)
void Person::greet(){
        cout << "My name is "<< getName() << ", I am " << getAge() << " years old and my gender is";
        if(getGender()){
            cout << " male" << endl;
        } else {
            cout << " female" << endl;
        }
}

int main(){
    cout << "How many people are here? There are: " << Person::counter_persons << endl; // we make a reference to the class itself. Sharing the value of the 'static' attribute, therefore not making a copy of this attribute for each object but a 'global-like' value that can be accessed through the class itself

    /*
        Output: How many people are here? There are: 0
    */

    Person p1 = Person("Joe", 77, true); //normal declaration, some space in memory will be set apart during compilling time
    //Sending the name of p1 as argument → using constructor method ; also the othe parameters as in-line assignation
   
    // p1.name = "Joe";
    // p1.age = 77;
    // p1.gender = true;
        //these are unaccesible due to encapsuling
   
    p1.setName("Xavier").setAge(40).setName("Robert"); //concatenating methods to set a different name. Only works when the last method is also a method returning this

    p1.greet();
    //using '.' notation to access variables and methods from the class

    cout << "How many people are here? There are: " << Person::counter_persons << endl;

    /*
        Output: How many people are here? There are: 1
    */

    Person *p2 = new Person("Wendy", 21, false); //declaration using pointers, memory space will be set apart during execution time

    // p2->name = "Wendy";
    // p2->age = 21;
    // p2->gender = false;

    // delete p2; //invoking destructor method, therefore manually cleaning memory

    p2->greet();
    // using '->' notation to access variables and methods, being a pointer object
    // After using destructor → [1]    9818 segmentation fault (core dumped)  ./objects
    // doesn't "exists" anymore

    cout << "How many people are here? There are: " << Person::counter_persons << endl;

    /*
        Output: How many people are here? There are: 2
    */

    return 0;
}