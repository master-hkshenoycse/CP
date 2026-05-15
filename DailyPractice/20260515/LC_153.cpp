#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0;
        int n=nums.size();
        int hi=n-1;
        
        if(hi==0){
            return nums[0];
        }
        
        while(hi>lo){
            int m=(hi+lo)/2;
            
            if(nums[lo]<nums[hi]){
                return nums[lo];
            }else if(nums[hi]<nums[m]){
                 lo=m+1;
            }else{
                 hi=m;
            }
        }
        return nums[lo];
        
    }
};