#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> sol(n);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(st.size()>0 and prices[st.top()]>prices[i]){
                st.pop();
            }

            sol[i]=prices[i];
            if(st.size()>0){
                sol[i]-=prices[st.top()];
            }

            st.push(i);
        }

        return sol;
        
    }
};