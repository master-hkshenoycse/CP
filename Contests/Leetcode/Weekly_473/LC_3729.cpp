#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        ll n=nums.size();
        map<ll,ll> help;
        help[0]=1;
        ll cs=0,ret=0;

        for(ll i=1;i<=n;i++){
            cs=cs+nums[i-1];
            cs%=k;
            ret=ret+help[cs];
            help[cs]++;
        }


        for(ll i=0;i<n;){
            int j=i;
            while(j<n && nums[i]==nums[j]){
                j++;
            }

            int len=j-i;
            for(ll l=1;l<len;l++){
                if((l*1ll*nums[i])%k==0)
                    ret=ret-(len-l);
            }

            i=j;
            
        }

        return ret;
    }
};