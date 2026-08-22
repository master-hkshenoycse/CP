#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        ll ans=0,n=nums.size();
        for(ll i=1;i<n;i++)
            ans+=max(0ll,nums[i-1]*1ll-nums[i]*1ll);
        
        return ans;
    }
};