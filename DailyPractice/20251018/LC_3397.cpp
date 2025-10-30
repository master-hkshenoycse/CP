#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size(),hi=-2e9,ans=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]-k > hi){
                hi=nums[i]-k;
                ans++;
            }else{
                int diff=abs((hi+1)-nums[i]);
                if(diff<=k){
                    hi++;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};