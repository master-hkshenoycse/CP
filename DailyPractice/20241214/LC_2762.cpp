#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    bool check(multiset<ll> &active){
        ll lo=*active.begin();
        ll hi=*(--active.end());
        return hi-lo<=2;
    }
    long long continuousSubarrays(vector<int>& nums) {
        ll ans=0,n=nums.size(),j=0;
        multiset<ll> active_nums;

        for(ll i=0;i<n;i++){
            active_nums.insert(nums[i]);
            while(j<i and check(active_nums)==0){
                active_nums.erase(active_nums.find(nums[j]));
                j++;
            }
            ans=ans+i-j+1;
        }

        return ans;

    }
};