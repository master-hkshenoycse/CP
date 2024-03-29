#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll ma=0;
        for(auto e:nums){
            ma=max(ma,e*1ll);
        }
        
        ll n=nums.size();
        vector<ll> csum(n+1,0);
        for(ll i=1;i<=n;i++){
            csum[i]=csum[i-1]+(nums[i-1]==ma);
        }
        
        ll ans=0;
        for(ll i=1;i<=n;i++){
            
            ll lo=i,hi=n,cnt=n+1;
            while(hi>=lo){
                ll mid=(hi+lo)/2ll;
                if(csum[mid]-csum[i-1]>=k){
                    cnt=min(cnt,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            
            ans=ans+n-cnt+1;
        }
        
        return ans;
    }
};