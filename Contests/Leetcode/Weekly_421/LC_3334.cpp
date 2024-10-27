#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxScore(vector<int>& nums) {
        ll n=nums.size(),ans=0;
        for(ll i=0;i<n+1;i++){
            
            ll gc=0,lc=1;
            for(ll j=0;j<n;j++){
                if(j==i){
                    continue;
                }
                gc=__gcd(gc,nums[j]*1ll);
                lc=(lc * nums[j])/__gcd(lc,nums[j]*1ll);
            }

            ans=max(ans,lc*gc);
        }

        return ans;
        
    }
};