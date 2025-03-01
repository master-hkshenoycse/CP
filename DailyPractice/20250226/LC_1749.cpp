#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int ans=0;
            
            int ms_so_far=0;
            int cs=0;
            
            for(int i=0;i<nums.size();i++){
                cs=max(nums[i],cs+nums[i]);
                if(cs<0)cs=0;
                
                ms_so_far=max(ms_so_far,cs);
                
            }
            ans=ms_so_far;
            ms_so_far=0;
            
            for(int i=0;i<nums.size();i++)nums[i]*=-1;
            cs=0;
            for(int i=0;i<nums.size();i++){
                cs=max(nums[i],cs+nums[i]);
                if(cs<0)cs=0;
                
                ms_so_far=max(ms_so_far,cs);
                
            }
            ans=max(ans,ms_so_far);
            return ans;
        }
    };