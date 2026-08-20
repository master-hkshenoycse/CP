#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll dp[17][2][10];
    ll solve(ll ind,ll ti,ll prev, vector<ll> &mark, string &s){
        if(ind==s.size())
            return 1;
        
        if(dp[ind][ti][prev] != -1)
            return dp[ind][ti][prev];

        ll lim=9;
        if(ti)
            lim=s[ind]-'0';
        ll ret=0;

        for(int i=0;i<=lim;i++){
            
            if(mark[ind]){
                if(i<prev)
                    continue;
                ret=ret+solve(ind+1,ti && i==lim,i,mark,s);
            }else{
                ret=ret+solve(ind+1,ti && i==lim,prev,mark,s);
            }
        }

        return dp[ind][ti][prev]=ret;
    }
    ll get_cnt(ll n,vector<ll> &mark_index){
        string num=to_string(n);
        while(num.size()<16)
            num='0'+num;
        memset(dp,-1,sizeof(dp));
        return solve(0,1,0,mark_index,num);
    }
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        vector<ll> mark_index(16,0);
        int row=0,col=0;
        for(auto d:directions){
            mark_index[row*4+col]=1;
            if(d=='D')
                row++;
            else
                col++;
        }

        mark_index[row*4+col]=1;
        l--;

        return get_cnt(r,mark_index)-get_cnt(l,mark_index);
    }
};