#include <bits/stdc++.h>
#define ll long long
using namespace std;
//https://practice.geeksforgeeks.org/contest/gfg-weekly-160-rated-contest/problems
class Solution {
  public:
    int maxGoodSubarrays(int n, vector<int> &arr) {
        // code here
        
        stack<int> st;
        vector<int> dp(n+1,0);
        vector<int> prefix_dp(n+1,0);
        
        for(int i=1;i<=n;i++){
            
            int prev=-1;
            while(st.size()>0 and arr[st.top()-1]<=arr[i-1]){
                st.pop();
            }
            
            if(st.size()>0){
                prev=st.top();
            }
            
            //dp[i]=dp[i-1];
            if(prev-1>=0){
                dp[i]=max(dp[i],prefix_dp[prev-1]+1);
            }
            
            prefix_dp[i]=max(prefix_dp[i-1],dp[i]);
            
            st.push(i);
            
            
        }
        
        return dp[n];
        

        
    }
};