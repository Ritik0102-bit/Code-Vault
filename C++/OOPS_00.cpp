#include<iostream>

using namespace std;

class Fruit{
    public:
    string name;
    string colour;
};

int main(){
    Fruit apple; // Object
    apple.name="Apple";
    apple.colour="Red";

    cout << apple.colour << endl;

    Fruit *Mango= new Fruit(); // Pointer Object
    Mango->name="Mango";
    Mango->colour="Yellow";

    cout << Mango->colour << endl;

    return 0;
}