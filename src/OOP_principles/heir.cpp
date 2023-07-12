#include <iostream>

using namespace std;

class Animal {
    protected: //all attributes and methods here will be only accessible to objects that heir from this class
        static int num_animals;
        string food;
    public:
        Animal();
        ~Animal();
        static int getNum_Animals(); //will be defined outside the class 

        string getFood(){
            return food;
        }

        void eating(Animal *a){
            cout << "This animal is eating " << a->getFood() << endl;
        }
};

int Animal::num_animals = 0; //defining 'num_animals' outside class with scope resolution operator (::)

Animal::Animal(){
    cout << "Creating animal... " << endl;
    num_animals++;
}

Animal::~Animal(){
    cout << "Deleting animal... " << endl;
    num_animals--;
} 
    //altering static value 'num_animals' through this methods

int Animal::getNum_Animals(){
    return num_animals;
} //defining method outside of class


class Herbivore : public Animal { 
    public:
        Herbivore() : Animal(){ //to alter the original constructor, besides the attribute 'food' is in parent class, we must point to it with ':' and the name of the original constructor
            this->food = "plants";
        } //'food' is a protected attribute, therefore only accessible through the children of class Animal

        void toGraze(){
            cout << "this animal is grazing..." << endl;
        }
}; //applying (public) inheritance, from a generic 'Animal' to 'Herbivore'

class Carnivore : public Animal {
    public:
        Carnivore() : Animal(){
            this->food = "meat";
        }

        void toHunt(){
            cout << "this animal is hunting..." << endl;
        }
};

class Omnivore : public Herbivore, public Carnivore { //multiple inheritance
    public:
        Omnivore() : Herbivore(), Carnivore(){} //using constructor with multiple inheritance concept
        
        //if we want to change the method eating to avoid ambiguity issue
        void eating(){
            cout << "This animal can eat whatever it likes..." << endl;
        }
};

int main() {
    Animal *a1 = new Animal(); //creating pointer instance
    Herbivore *a2 = new Herbivore();
    Carnivore *a3 = new Carnivore();
    Omnivore *a4 = new Omnivore(); // because it inherits from 2 classes, the constructor gets invoked twice, therefore increasing num_animals by 2

    cout << "number of animals: " << Animal::getNum_Animals() << endl;

    a1->eating(a1);

    a2->toGraze();
    a1->eating(a2); //calling this method to know which kind of food is this animal eating 
    //also, now we apply polimorfism to the class Animal. Taking as base class 'Animal', we pass a2 as the animal recognizing is a herbivore
   
    a3->toHunt();
    a1->eating(a3); //same but with the carnivore

    cout << "An omnivore has appeared..." << endl;
    a4->Herbivore::eating(a2); //calling method 'eating()' pointing which parent class will use that method, because 'eating()' invokes method getFood(), and such according to the parent class points to a different value in the same memory register
    // also now is taking the herbivore and the object of herbivore to call the method 'eating()' but using as base class the omnivore (a4)

    a4->eating();

    delete a1;

    cout << "number of animals: " << Animal::getNum_Animals() << endl;

    return 0;
}