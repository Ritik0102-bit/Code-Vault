
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> Stock_Span(vector<int>& prices,int n){
    vector<int> ans(n);
    stack<int> s; // store previous greater element

    for(int i=0;i<n;i++){
        while(!s.empty() && prices[i] > prices[s.top()]){
            s.pop();
        }

        if(s.empty()){
            ans[i] = i + 1;
        }
        else{
            ans[i] = i - s.top();
        }
        s.push(i);
    }

    return ans;
}

int main(){
    vector<int> prices = {100,80,60,70,60,75,85};
    int n = 7;

    vector<int> ans = Stock_Span(prices,n);

    for(int i:ans){
        cout << i << " ";
    }
}