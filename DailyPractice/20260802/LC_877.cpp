#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[505][505];
    int memo[505][505];
    
    int solve(int st,int en,int c,vector<int> &p){
        if(st>en){
            return 0;
        }
        
        if(st==en){
            if(c==0) return p[st];
            return -1*p[st];
        }
        
        if(memo[st][en]){
            return dp[st][en];
        }
        
        memo[st][en]=1;
        int res;
        
        
        if(c%2==0){
            res=INT_MIN;
            res=max(res,p[st]+solve(st+1,en,c+1,p));
            res=max(res,p[en]+solve(st,en-1,c+1,p));        
        }else{
            res=INT_MAX;
            res=min(res,solve(st+1,en,c+1,p)-p[st]);
            res=min(res,solve(st,en-1,c+1,p)-p[en]);
        }
        
        
        return dp[st][en]=res;
        
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int x=solve(0,n-1,0,piles);
        return x>0;
    }
};