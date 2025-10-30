#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        stack<int> st;
        int n=weight.size();
        vector<int> dp(n+1,0);

        for(int i=1;i<=n;i++){
            while(st.size()>0 && weight[st.top()-1]<=weight[i-1]){
                st.pop();
            }

            if(st.size()>0){
                dp[i]=dp[st.top()-1]+1;
            }
            st.push(i);
            dp[i]=max(dp[i],dp[i-1]);
        }

        return dp[n];
    }
};