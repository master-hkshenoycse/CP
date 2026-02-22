#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int mod=1e9+7;
    int solve(int ind, int g,vector<vector<int> >&dp,vector<vector<int> >&mat){
        if(ind == mat.size())
            return g==1;

        if(dp[ind][g] != -1)
            return dp[ind][g];
        
        int ret=0;
        for(int i=0;i<mat[0].size();i++){
            int nx_g=__gcd(g,mat[ind][i]);
            ret=ret+solve(ind+1,nx_g,dp,mat);
            ret%=mod;
        }
        return dp[ind][g]=ret;
    }
    int countCoprime(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int> >dp(n,vector<int> (151,-1));
        return solve(0,0,dp,mat);

    }
};