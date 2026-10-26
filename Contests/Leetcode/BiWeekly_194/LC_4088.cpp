#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n=nums.size(),valley_sum=0,peak_sum=0;

        for(int i=0;i<n;i++){
            if(i+1<n && i-1>=0 && nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                peak_sum+=nums[i];
            }
            if(i+1<n && i-1>=0 && nums[i]<nums[i-1] && nums[i]<nums[i+1]){
                valley_sum+=nums[i];
            }
        }

        return peak_sum-valley_sum;
    }
};