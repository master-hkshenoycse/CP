#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll solve(ll l,ll r,string &s,vector<ll> &csum_,ll encCost,ll flatCost){
        
        if(l>r){
            return 0;
        }

        ll cnt_1=csum_[r];
        if(l-1>=0)
            cnt_1-=csum_[l-1];
        
        ll curr_cost=0;
        ll len=(r-l+1);

        if(cnt_1==0){
            curr_cost=flatCost;
        }else{
            curr_cost=len*cnt_1*encCost;
        }

        if(len%2){
            return curr_cost;
        }else{
            ll mid=(l+r)/2;
            return min(curr_cost, solve(l,mid,s,csum_,encCost,flatCost)+solve(mid+1,r,s,csum_,encCost,flatCost));
        }
    }
    long long minCost(string s, int encCost, int flatCost) {
        ll n=s.size();
        vector<ll> csum_(n,0);

        for(ll i=0;i<n;i++){
            csum_[i]=(s[i]-'0');
            if(i-1>=0)
                csum_[i]+=csum_[i-1];
        } 

        return solve(0,n-1,s,csum_,encCost,flatCost);

    }
};