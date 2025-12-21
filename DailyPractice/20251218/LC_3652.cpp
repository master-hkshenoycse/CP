#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_csum(vector<ll> &csum,ll l,ll r){
        if(l>r){
            return 0;
        }
        ll ret=csum[r];
        if(l-1>=0){
            ret-=csum[l-1];
        }
        return ret;
    }
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        ll n=prices.size();
        vector<ll> cum_profit(n,0),cum_prices(n,0);

        for(ll i=0;i<n;i++){
            cum_profit[i]=prices[i]*strategy[i];
            cum_prices[i]=prices[i];
            if(i-1>=0){
                cum_profit[i]+=cum_profit[i-1];
                cum_prices[i]+=cum_prices[i-1];
            }
        }

        ll ans=cum_profit[n-1];

        for(ll i=0;i+k-1<n;i++){
            ll tot=get_csum(cum_profit,0,i-1)+get_csum(cum_profit,i+k,n-1);
            tot+=get_csum(cum_prices,i+k/2,i+k-1);
            ans=max(ans,tot);
        }

        return ans;
           
    }
};