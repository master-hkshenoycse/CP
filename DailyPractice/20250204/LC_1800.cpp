#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        
        int i=0;
        
        while(i<n){
            int s=nums[i];
            
            int j=i+1;
            
            while(j<n and nums[j]>nums[j-1]){
                s+=nums[j];
                j++;
            }
            i=j;
            
            
            ans=max(ans,s);
        }
        return ans;
    }
};