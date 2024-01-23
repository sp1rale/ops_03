#include <iostream>
#include <string>

using namespace std;

class HomeAnimal {
protected:
    string name;

public:
    HomeAnimal(const string& animalName) : name(animalName) {}

    virtual void sound() const = 0;
    virtual void show() const {
        cout << "Name: " << name << "\n";
    }
    virtual void type() const = 0;

    virtual ~HomeAnimal() {}
};

class Dog : public HomeAnimal {
public:
    Dog(const string& name) : HomeAnimal(name) {}

    void sound() const override {
        cout << "Woof! Woof!\n";
    }

    void type() const override {
        cout << "Dog\n";
    }
};

class Cat : public HomeAnimal {
public:
    Cat(const string& name) : HomeAnimal(name) {}

    void sound() const override {
        cout << "Meow! Meow!\n";
    }

    void type() const override {
        cout << "Cat\n";
    }
};

class Parrot : public HomeAnimal {
public:
    Parrot(const string& name) : HomeAnimal(name) {}

    void sound() const override {
       cout << "Squawk! Squawk!\n";
    }

    void type() const override {
        cout << "Parrot\n";
    }
};

class Hamster : public HomeAnimal {
public:
    Hamster(const string& name) : HomeAnimal(name) {}

    void sound() const override {
        cout << "Squeak! Squeak!\n";
    }

    void type() const override {
        cout << "Hamster\n";
    }
};

int main() {
    Dog myDog("Blondi");
    Cat myCat("Sir");
    Parrot myParrot("Gustavo");
    Hamster myHamster("Kent");

    myDog.sound();
    myDog.show();
    myDog.type();

    myCat.sound();
    myCat.show();
    myCat.type();

    myParrot.sound();
    myParrot.show();
    myParrot.type();

    myHamster.sound();
    myHamster.show();
    myHamster.type();

    return 0;
}
