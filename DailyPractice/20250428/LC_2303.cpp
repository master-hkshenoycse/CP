#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll n=nums.size();
        vector<ll> csum(n,0);
        
        for(ll i=0;i<n;i++){
            csum[i]=nums[i];
            if(i-1>=0)csum[i]+=csum[i-1];
        }
        
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(nums[i]>=k){
                continue;
            }
            ll lo=i,hi=n-1,r=i;
            
            while(hi>=lo){
                ll mid=(hi+lo)/2ll;
                
                ll len=mid-i+1;
                ll s=csum[mid];
                if(i-1>=0)s-=csum[i-1];
                
                if(s*len<k){
                    r=max(mid,r);
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }
    
            ans=ans+(r-i+1);
        }
        
        
        return ans;
    }
};