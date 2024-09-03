#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[105][1030];
    int solve_dp(int ind,int mask,map<int,vector<int> >&index_){
        if(ind==0){
            return 0;
        }
        
        if(dp[ind][mask] != -1){
            return dp[ind][mask];
        }
        
        int res=solve_dp(ind-1,mask,index_);
        
        for(auto i:index_[ind]){
            if((mask & (1<<i))==0){
                res=max(res,ind+solve_dp(ind-1,mask|(1<<i),index_));
            }
        }
        
        return dp[ind][mask]=res;
    }
    int maxScore(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        map<int,vector<int> > index_;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                index_[grid[i][j]].push_back(i);
            }
        }
        
        return solve_dp(100,0,index_);
    }
};