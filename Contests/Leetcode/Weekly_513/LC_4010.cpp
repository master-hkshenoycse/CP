#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        ll n=nums.size();
        ll ans=0;

        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                ll gc=__gcd(nums[i],nums[j]);
                ans=max(ans,(nums[i]*1ll*nums[j]*1ll)/(gc*gc));
            }
        }

        return ans;
    }
};