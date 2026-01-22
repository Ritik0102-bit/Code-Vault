// Inheritance

#include<iostream>

using namespace std;

class Parent{

public:
    int x;

protected:
    int y;

private:
    int z;
};

class Child_1: public Parent{
    // In this Class
    //x will remain public
    //y will remain protected
    //z will not be accessible
};


class Child_2: private Parent{
    // In this Class
    //x will be private
    //y will be private
    //z will be inaccessible
};

class Child_3: protected Parent{
    // In this Class
    //x will be protected
    //y will be protected
    //z will be inaccessible
};

int main(){
    
    return 0;
}