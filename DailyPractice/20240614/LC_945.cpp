#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0;
        for(int i=1;i<n;i++){
            int req=nums[i-1]+1;
            if(nums[i]<req){
                ans=ans+req-nums[i];
                nums[i]=req;
            }
        }
        return ans;
    }
};