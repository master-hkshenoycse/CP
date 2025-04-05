#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll ma=0,n=nums.size();
        vector<ll> suff(n+2,0);
        for(ll i=n;i>=1;i--){
            suff[i]=nums[i-1];
            suff[i]=max(suff[i],suff[i+1]);
        }
        
        ll ans=0;
        
        for(ll i=1;i<=n;i++){
            ans=max(ans,(ma-(ll)nums[i-1])*suff[i+1]);
            ma=max(ma,(ll)nums[i-1]);
        }
        
        return ans;
    }
};