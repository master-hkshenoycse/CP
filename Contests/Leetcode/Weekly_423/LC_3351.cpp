#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
    
        map<ll,ll> help,cnt;
        ll mod=1e9+7,ans=0;

        for(auto e:nums){
            ll curr=0;
            ll cnt_sub=0;
            if(help.find(e-1) != help.end()){
                curr=(curr+help[e-1]+cnt[e-1]*e)%mod;
                cnt_sub=(cnt_sub+cnt[e-1])%mod;
            }

            if(help.find(e+1) != help.end()){
                curr=(curr+help[e+1]+cnt[e+1]*e)%mod;
                cnt_sub=(cnt_sub+cnt[e+1])%mod;
            }

            curr=(curr +e)%mod;
            cnt_sub=(cnt_sub+1)%mod;

            help[e]=(help[e]+curr)%mod;
            cnt[e]=(cnt[e]+cnt_sub)%mod;

            ans=(ans+curr)%mod;
            
        }

        return ans;
    }
};