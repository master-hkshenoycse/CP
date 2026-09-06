#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll dp[17][2][2][10];
    ll solve(ll ind, ll ti, ll st,ll prev, ll k,string &num){
        if(ind==num.size())
            return 1;
        
        if(dp[ind][ti][st][prev] != -1)
            return dp[ind][ti][st][prev];
        
        ll ret=0;
        ll lim=9;
        if(ti)
            lim=num[ind]-'0';

        for(int i=0;i<=lim;i++){
            if(st){
                if(abs(i-prev)<=k)
                    ret=ret+solve(ind+1,ti && (i==lim),st,i,k,num);
            }else{
                ret=ret+solve(ind+1,ti && (i==lim),i>0,i,k,num);
            }
        }

        return dp[ind][ti][st][prev]=ret;
        
    }

    ll get_res(ll n,ll k){
        memset(dp,-1,sizeof(dp));
        string num=to_string(n);
        return solve(0,1,0,0,k,num);
    }

    ll get_cnt(ll n,ll k){
        int cnt=0;
        for(ll i=0;i<=n;i++){
            string x=to_string(i);
            int f=1;
            for(int i=1;i<x.size();i++){
                if(abs(x[i]-x[i-1])>k)
                    f=0;
            }
            cnt+=f;
        }
        return cnt;
    }
    long long goodIntegers(long long l, long long r, int k) {
        return get_res(r,k)-get_res(l-1,k);
    }
};