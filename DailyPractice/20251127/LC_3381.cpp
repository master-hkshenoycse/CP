#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        map<ll,ll> help;
        help[0]=0;

        ll n=nums.size(),ans=-1e18,cs=0;
        for(ll i=1;i<=n;i++){
            cs=cs+nums[i-1];
            ll ind=i%k;
            if(help.find(ind)==help.end()){
                help[ind]=cs;
            }else{
                ans=max(ans,cs-help[ind]);
                help[ind]=min(help[ind],cs);  
            }
        }
        return ans;
    }
};