#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        ll n=nums.size();
        vector<ll> suffix_min(n),suffix_max(n);

        for(ll i=n-1;i>=0;i--){
            suffix_min[i]=nums[i];
            suffix_max[i]=nums[i];

            if(i+1<n){
                suffix_max[i]=max(suffix_max[i],suffix_max[i+1]);
                suffix_min[i]=min(suffix_min[i],suffix_min[i+1]);
            }
        }

        ll ans=-1e18;

        if(m==1){
            for(ll i=0;i<n;i++){
                ans=max(ans,nums[i]*1ll*nums[i]*1ll);
            }
        }else{
            for(ll i=0;i<n;i++){
                if(i+m-1<n){
                    ans=max(ans,nums[i]*1ll*suffix_max[i+m-1]);
                    ans=max(ans,nums[i]*1ll*suffix_min[i+m-1]);
                }
            }
        }

        return ans;
    }
};