#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size(),ans=0,i=0;
        
        while(i<n){
            int j=i;
            while(j<n and nums[i]==nums[j]){
                j++;
            }
            if(j<n and i-1>=0 and nums[j]>nums[i] and nums[i-1]>nums[i]){
                ans++;
            }
            
            if(j<n and i-1>=0 and nums[j]<nums[i] and nums[i-1]<nums[i]){
                ans++;
            }
            
            i=j;
        }
        return ans;
        
        
    }
};