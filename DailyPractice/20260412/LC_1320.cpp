#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_dist(int x,int y){
        int row_x=x/6;
        int col_x=x%6;
        int row_y=y/6;
        int col_y=y%6;
        return abs(row_x-row_y)+abs(col_x-col_y);
    }

    int solve(int ind,int px,int py,vector<vector<vector<int> > >&dp, string &w){
        if(ind==w.size())
            return 0;

        if(dp[ind][px][py] != -1 )
            return dp[ind][px][py];
        
        int ret=INT_MAX;
        int curr=w[ind]-'A';
        ret=min(ret,get_dist(px,curr)+solve(ind+1,curr,py,dp,w));
        ret=min(ret,get_dist(py,curr)+solve(ind+1,px,curr,dp,w));
        return dp[ind][px][py]=ret;
    }

    int minimumDistance(string word) {
        int n=word.size();
        vector<vector<vector<int> > > dp(n+1,vector<vector<int> > (26,vector<int> (26,-1)));
        int ret=INT_MAX;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                ret=min(ret,solve(0,i,j,dp,word));
            }
        }
        return ret;
    }
};