#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int curr,int day,vector<vector<int> >&dp,vector<vector<int> >&stay,vector<vector<int> >&travel,int k){
        if(day==k){
            return 0;
        }

        if(dp[curr][day] != -1){
            return dp[curr][day];
        }

        int res=stay[day][curr]+solve(curr,day+1,dp,stay,travel,k);
        for(int i=0;i<travel.size();i++){
            res=max(res,travel[curr][i]+solve(i,day+1,dp,stay,travel,k));
        }
        return dp[curr][day]=res;
    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<vector<int> > dp(n,vector<int> (k,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,solve(i,0,dp,stayScore,travelScore,k));
        }
        return ans;

    }
};