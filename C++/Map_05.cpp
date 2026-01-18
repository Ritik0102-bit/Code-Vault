#include<iostream>
#include<map>

using namespace std;

int main(){

    multimap<string, int> directory;

    directory.insert(make_pair("urvi", 6292001));
    directory.insert(make_pair("saghvi", 653902));
    directory.insert(make_pair("saghvi", 900000));
    //directory["urvi"] = 278192; not allowed
    // If you wrote directory["saghvi"] = 12345;, the compiler wouldn't know which "saghvi" you want to update. Do you want to update the first one? The second one? Or insert a new one?

    // Because of this confusion, the C++ Standard Library developers completely removed the [] operator for multimap.

    for(auto pair:directory){
        cout<<"Name - "<<pair.first<<endl;
        cout<<"Phone no - "<<pair.second<<endl;
    }

    return 0;
}