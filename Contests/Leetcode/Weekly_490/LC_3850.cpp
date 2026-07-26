#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    map<array<ll,3>, int> dp;
    pair<ll,ll> resolve(ll num,ll den){
        ll gc=__gcd(num,den);
        num/=gc;
        den/=gc;
        return {num,den};
    }

    ll solve(vector<int> &a, ll k, ll pos, ll num=1, ll den=1){
        ll n=a.size();
        auto pt=resolve(num,den);
        num=pt.first;
        den=pt.second;

        if(pos==n)
            return num==k && den==1;
        
        if(dp.count({pos, num, den}))
            return dp[{pos, num, den}];
        
        ll ans=solve(a,k,pos+1,num,den);
        ans+=solve(a, k, pos+1, num*a[pos], den);
        ans+=solve(a, k, pos+1, num, den * a[pos]);
        return dp[{pos, num, den}]=ans;
    }
    int countSequences(vector<int>& nums, long long k) {
        dp.clear();
        return solve(nums, k, 0);
    }
};