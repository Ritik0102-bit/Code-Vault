#include<iostream>
#include<map>

using namespace std;

int main(){
    map< string , int > m;

    m["aditya"]=123456;
    m["saurav"]=123456;
    m["sumeet"]=123456;
    m["shiven"]=123456;

    for(auto element : m){
        cout << element.first  << " : " << element.second << endl;
    }
    
    // Printing map using iterator

    cout << "Printing map using iterator " << endl;
    map<string,int> :: iterator itr;
    for(itr=m.begin() ; itr!=m.end() ; itr++){
        cout << itr->first  << " : " << itr->second << endl;
    }
    
    // Printing map using iterator in reverse order
    
    cout << "Printing map using iterator in reverse order" << endl;
    map<string,int> :: reverse_iterator itr2;
    for(itr2=m.rbegin() ; itr2!=m.rend() ; itr2++){
        cout << itr2->first  << " : " << itr2->second << endl;
    }

    return 0;
}