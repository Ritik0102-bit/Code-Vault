// Queue Using STL

#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> qu;

    qu.push(0);
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.push(50);

    // Printing the Queue
    while(!qu.empty()){
        cout << qu.front() << "  ";
        qu.pop();
    }
    cout << endl;

    return 0;
}