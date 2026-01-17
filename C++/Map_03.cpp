#include<iostream>
#include<unordered_map>

using namespace std;

int main(){

    unordered_map<int, string> record;
    //roll no, name

    record.insert(make_pair(3, "ria"));
    record[1] = "bali";
    record[2] = "animesh";
    record[3] = "payal";

    for(auto pair:record){
        cout<<"Roll no - "<<pair.first<<endl;
        cout<<"Name - "<<pair.second<<endl;
    }

    unordered_map<string, int> umap;

    // 1. Insertion
    umap.insert({"Apple", 10});
    umap["Banana"] = 20;

    // 2. Search
    if (umap.find("Apple") != umap.end()) {
        cout << "Apple found!" << endl;
    }

    // 3. Check existence using count
    if (umap.count("Banana")) {
        cout << "Banana is present." << endl;
    }

    // 4. Access (Safe vs Unsafe)
    cout << "Price of Apple: " << umap.at("Apple") << endl; 
    // cout << umap.at("Mango"); // This would crash (exception)
    cout << "Price of Mango: " << umap["Mango"] << endl; // Creates "Mango" with value 0

    // 5. Erase
    umap.erase("Apple"); // Removes Apple

    // 6. Size
    cout << "Current size: " << umap.size() << endl;


    return 0;
}