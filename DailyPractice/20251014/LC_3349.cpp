#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> inc_len(n,1);
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                inc_len[i]=inc_len[i+1]+1;
            }
        }

        for(int i=0;i<n;i++){
            if(inc_len[i]>=k and i+k<n and inc_len[i+k]>=k){
                return 1;
            }
        }

        return 0;
    }
};