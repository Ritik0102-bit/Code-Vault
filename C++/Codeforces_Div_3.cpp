#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


int Time_Taken_To_Remove_MaxLength_Line(int n,string s){
    int max_length = 0;
    int len = 0;

    for(int i=0;i<n;i++){
        if(s[i] == '#'){
            len++;
            max_length = max(len,max_length);
        }
        else{
            len = 0;
        }
    }

    return (max_length % 2 == 0) ? max_length/2 : max_length/2 + 1;
}

int main(){
    int no_of_test_cases;
    int n;
    string s;

    cin >> no_of_test_cases;

    for(int i=0;i<no_of_test_cases;i++){
        cin >> n ;
        cin >> s;

        cout << Time_Taken_To_Remove_MaxLength_Line(n,s) << endl;
    }
}