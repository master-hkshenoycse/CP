#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod=1e9+7;
    int solve_dp(int ind,int rem,vector<int> &values_req,vector<vector<int> >&dp){
        if(rem<0){
            return 0;
        }
        if(ind<0){
            return rem==0;
        }
        
        if(dp[ind][rem]!=-1){
            return dp[ind][rem];
        }
        
        int x=values_req[ind];
        int res=0;
        if(x !=-1 and x!=rem){
            return dp[ind][rem]=0;
        }
        for(int i=0;i<=ind;i++){
            res=(res+solve_dp(ind-1,rem-i,values_req,dp))%mod;
            
        }
        
        return dp[ind][rem]=res;
    }
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        int m=requirements.size();
        
        vector<int> values_req(n,-1);
        for(auto r:requirements){
            values_req[r[0]]=r[1];
        }
        
        vector<vector<int> > dp(n+1,vector<int> (505,-1));
        
        return solve_dp(n-1,values_req[n-1],values_req,dp);
    }
};