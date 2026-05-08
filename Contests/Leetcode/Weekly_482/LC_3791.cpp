#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll dp[17][2][3][315];
    ll solve_dp(ll ind,ll ti,ll st,ll bal,string &num){
        if(ind==num.size())
            return bal==145 && st!=0;
        
        if(dp[ind][ti][st][bal] != -1)
            return dp[ind][ti][st][bal];
        
        int dig=num[ind]-'0';
        if(ti==0)
            dig=9;
        
        ll ret=0;

        for(int i=0;i<=dig;i++){
            int nx_ti=(ti && (i==dig));

            if(st==1){
                ret=ret+solve_dp(ind+1,nx_ti,2,bal+i,num);
            }else if(st==2){
                ret=ret+solve_dp(ind+1,nx_ti,1,bal-i,num);
            }else if(st==0){
                if(i==0){
                    ret=ret+solve_dp(ind+1,nx_ti,0,bal+0,num);
                }else{
                    ret=ret+solve_dp(ind+1,nx_ti,2,bal+i,num);
                }
            }
        }

        return dp[ind][ti][st][bal]=ret;

    }
    long long countBalanced(long long low, long long high) {
        //{ind,ti,st,bal};

        string num_low=to_string(low-1);
        string num_hi=to_string(high);
        memset(dp,-1,sizeof(dp));
        ll ret=solve_dp(0,1,0,145,num_hi);
        
        memset(dp,-1,sizeof(dp));
        ret-=solve_dp(0,1,0,145,num_low);
        return ret;
    }
};