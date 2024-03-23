#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int st,int en,vector<vector<int> > &dp,string &s){
        if(st>en){
            return 0;
        }
        if(st==en){
            return 1;
        }
        if(dp[st][en] != -1){
            return dp[st][en];
        }

        int ans=1+solve(st+1,en,dp,s);
        for(int i=st+1;i<=en;i++){
            if(s[i]==s[st]){
                ans=min(ans,solve(st,i-1,dp,s)+solve(i+1,en,dp,s));
            }
        }

        return dp[st][en]=ans;
    }
    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int> > dp(n,vector<int> (n,-1));
        return solve(0,n-1,dp,s);

    }
};