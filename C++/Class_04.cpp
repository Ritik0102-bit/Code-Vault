#include <iostream>
#include <vector>
#include <string>


using namespace std;
// Friend function is a function that allows access to private members of the class.
// It is defined outside the class but can access private members of the class, but declared inside the class

class Chai{
    private:
        string teaName;
        int servings;

    public:
        Chai(string name, int serve): teaName(name), servings(serve){}

        friend bool compareServings(const Chai &chai1, const Chai &chai2); // friend function declaration
        // friend function can be defined outside the class, but it is declared inside the class

        void display() const {
            cout << "teaname: " << teaName << endl;
        }

};

// friend function definition
bool compareServings(const Chai &chai1, const Chai &chai2){
    return chai1.servings > chai2.servings;
}

int main(){
    Chai masalaChai("Masala Chai", 14);
    Chai gingerChai("Ginger Chai", 8);

    masalaChai.display();
    gingerChai.display();

    if(compareServings(masalaChai, gingerChai)){
        cout << "Masala chai is having MORE servings" << endl;
    } else {
        cout << "Masala chai is having LESS servings" << endl;

    }


}