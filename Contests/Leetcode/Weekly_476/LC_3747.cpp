#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll dp[18][2][2];
    ll solve(ll idx,ll st,ll ti,string &s){
        if(idx==s.size())
            return st;

        if(dp[idx][st][ti] != -1)
            return dp[idx][st][ti];
        
        int dig=s[idx]-'0';
        ll ret=0;
        for(int i=0;i<=9;i++){
            if(i==0 && st)
                continue;
            
            if(ti){
                if(i>dig){
                    break;
                }
                ret=ret+solve(idx+1,i!=0,i==dig,s);
            }else{
                ret=ret+solve(idx+1,i!=0,0,s);
            }
        }

        return dp[idx][st][ti]=ret;
    }
    long long countDistinct(long long n) {
        memset(dp,-1,sizeof(dp));

        string num=to_string(n);
        return solve(0,0,1,num);
    }
};