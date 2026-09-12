#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int ans=0,prev_max=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(i-k>=0){
                prev_max=max(prev_max,nums[i-k]);
                ans=max(ans,prev_max+nums[i]);
            }
        }   
        return ans;
    }
};