#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n=nums.size();
        int ans=0;
        vector<int> dp1(n+1,1),dp2(n+1,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])dp1[i]=max(dp1[i],dp1[j]+1);
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j])dp2[i]=max(dp2[i],dp2[j]+1);
            }
            if(dp1[i]+dp2[i]-1>=3 and dp1[i]>=2 and dp2[i]>=2)ans=max(ans,dp1[i]+dp2[i]-1);
        }
        
    
        
            
            
        return n-ans;
    }
};