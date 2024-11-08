#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll solve(ll st_r,ll st_f,vector<int> &robot,vector<vector<int>> &factory,vector<vector<ll> >&dp){
        if(st_r==robot.size()){
            return 0;
        }

        if(st_f==factory.size()){
            return 1e18;
        }

        if(dp[st_r][st_f] != -1){
            return dp[st_r][st_f];
        }

        ll res=1e18;
        ll lim=factory[st_f][1];
        ll p=factory[st_f][0];
        res=solve(st_r,st_f+1,robot,factory,dp);

        ll ex=0;
        for(int i=st_r;i<robot.size();i++){
            ex=ex+abs(p-robot[i]*1ll);
            if(i-st_r+1>lim){
                break;
            }
            res=min(res,ex+solve(i+1,st_f+1,robot,factory,dp));
        }


        return dp[st_r][st_f]=res;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        int n=robot.size(),m=factory.size();
        vector<vector<ll> > dp(n,vector<ll>(m,-1));

        return solve(0,0,robot,factory,dp);


    }
};