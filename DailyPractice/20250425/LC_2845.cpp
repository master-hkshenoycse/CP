#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        ll n=nums.size();
        
        vector<ll> csum(n+1,0);
        map<ll,ll>help;
        help[0]=1;
        ll ans=0;
        
        for(ll i=1;i<=n;i++){
            csum[i]=csum[i-1];
            if(nums[i-1]%modulo==k){
                csum[i]++;
            }
            
            csum[i]%=modulo;
            
            ll req=(csum[i]-k)%modulo;
            if(req<0){
                req+=modulo;
            }
            ans=ans+help[req];
            
            
            help[csum[i]]++;
        }
        
        
        
        
        
        return ans;
        
    }
};