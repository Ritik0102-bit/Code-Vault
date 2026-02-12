// Stock Span Problem

// Given a series of N daily price quotes for a stock, we need to calculate the span of the stock's price for all N days. The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

// The approach to find the stock span is going to be that we will find the Previous Greater Element (PGE)
// & then we just find distance between current element and PGE


#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> Stock_span(vector<int> v) {
    vector<int> res(v.size(), -1);
    stack<int> st;

    for (int i = 0; i < v.size(); i++) {
        // Pop elements that are smaller or equal to current
        while (!st.empty() && v[st.top()] <= v[i]) {
            st.pop();
        }
        
        // If stack has items, the top is the Previous Greater
        if (!st.empty()) {
            res[i] = st.top();
        }
        
        // Push current value index
        st.push(i);
    }
    return res;
}


int main(){
    vector<int> v={100, 80 , 60 , 70 , 60 , 75 , 85};

    vector<int> result=Stock_span(v);

    for(int i=0;i<result.size();i++){
        cout << i-result[i] << "  ";
    }

    return 0;
}