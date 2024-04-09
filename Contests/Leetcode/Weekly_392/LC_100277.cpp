#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        ll n=nums.size();
        ll med_idx=n/2;
        
        ll ans=0;
        sort(nums.begin(),nums.end());
        for(ll i=0;i<n;i++){
            if(i<=med_idx){
                if(nums[i]>k){
                    ans=ans+(nums[i]-k);
                    nums[i]=k;
                }
            }else{
                if(nums[i]<k){
                    ans=ans+(k-nums[i]);
                    nums[i]=k;
                }
            }
        }
        
        sort(nums.begin(),nums.end());
        
        ans+=abs(nums[med_idx]-k);
        
        return ans;
        
        
    }
};