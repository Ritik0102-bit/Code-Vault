// Prefix To Postfix Conversion

#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

string Prefix_To_Postfix(string s){
    stack<string> st;

    for(int i=s.size()-1;i>=0;i--){
        if(s[i]==' '){
            continue;
        }

        if(isdigit(s[i])){
            string num="";
            while(i>=0  && isdigit(s[i])){
                num=s[i] + num;
                i--;
            }
            i++;
            st.push(num);
        }
        
        else{
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            string new_expression= s1 + " " + s2 + " " + s[i];
            st.push(new_expression);
        }
    }
    return st.top();
}

int main(){
    string s="* - 10 20 + 500 600";
    cout << Prefix_To_Postfix(s);
}