#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix_lnd(n,0),suffix_lnd(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            prefix_lnd[i]=1;
            if(i-1>=0 && nums[i-1]<=nums[i])
                prefix_lnd[i]=prefix_lnd[i-1]+1;
            ans=max(ans,prefix_lnd[i]);
        }
        if(ans<n)
            ans++;
        for(int i=n-1;i>=0;i--){
            suffix_lnd[i]=1;
            if(i+1<n && nums[i+1]>=nums[i])
                suffix_lnd[i]=suffix_lnd[i+1]+1;
        }

        for(int i=0;i<n;i++){
            if(i+2<n){
                if(nums[i]<=nums[i+2])
                    ans=max(ans,prefix_lnd[i]+1+suffix_lnd[i+2]);
            }
        }

        return ans;
        
    }
};