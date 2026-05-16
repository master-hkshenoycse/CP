#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-1;
        
        while(lo<hi){
            if(nums[lo]<=nums[hi]){
                hi--;
            }else{
                lo++;
            }
        }
        return nums[lo];
        
    }
};