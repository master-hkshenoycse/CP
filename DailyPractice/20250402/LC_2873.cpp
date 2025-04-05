#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll n=nums.size();
        ll ans=0;
        
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                for(ll k=j+1;k<n;k++){
                    ans=max(ans,((ll)nums[i]-(ll)nums[j])*((ll)nums[k]));
                }
            }
        }
        
        return ans;
    }
};