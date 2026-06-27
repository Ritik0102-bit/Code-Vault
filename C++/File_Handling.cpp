#include<iostream>
#include<fstream>

using namespace std;

int main(){
    fstream file("Notes.txt");
    file << "Hello World" << endl;
    file << "Hello World" << endl;
    file << "Hello World" << endl;

    string line;

    file.seekg(0);

    while(getline(file,line)){
        cout << line << endl;
    }

    file.close();

    return 0;
}