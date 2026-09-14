#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        int n=nums.size();
        ll curr=k;
        ll ans=0;

        for(auto e:nums){
            ll req=max(0ll,e*1ll-curr);
            
            req=(req+k-1)/k;
            ans=(ans+req)%mod;
            curr+=req*k;
            curr-=e;
            //cout<<req<<" "<<curr<<endl;
        }

        //cout<<ans<<endl;
        ans=(ans*(ans+1))/2ll;
        ans%=mod;

        return ans;
    }
};