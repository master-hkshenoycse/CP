#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(),ans=1;
        for(int i=0;i<n;i++){
            int j=i+1,len=1;
            
            while(j<n and nums[j]>nums[j-1]){
                j++;
                len++;
            }
            
            ans=max(ans,len);
            
            j=i+1,len=1;
            
            while(j<n and nums[j]<nums[j-1]){
                j++;
                len++;
            }
            
            ans=max(ans,len);
        }
        
        return ans;
    }
};