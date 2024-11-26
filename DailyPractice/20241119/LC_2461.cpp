#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll csum[200005];
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll n=nums.size();
        
        for(ll i=1;i<=n;i++){
            csum[i]=csum[i-1]+nums[i-1];
        }
        
        ll ans=0,st=0;
        map<ll,ll> help;
        
        for(ll i=1;i<=n;i++){
            
            if(help.find(nums[i-1]) != help.end()){
                st=max(st,help[nums[i-1]]);
            }
            
            if(i-st>=k)ans=max(ans,csum[i]-csum[i-k]);        
            help[nums[i-1]]=i;
            
        }
        
        
        return ans;
            
            
    }
};