#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
         int cs=0,n=nums.size(),s=0,tot_sum=0;
        for(auto e:nums){
            tot_sum+=e;
        }
        
        
        for(int i=0;i<n;i++){
            cs=cs+nums[i];
            nums[i]=abs((cs-nums[i])-(tot_sum-cs));
        }
        
        return nums;
    }
};