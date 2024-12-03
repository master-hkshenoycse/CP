#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX,n=nums.size();
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s=s+nums[j];
                if(j-i+1>=l and j-i+1<=r and s>0){
                    ans=min(ans,s);
                }
            }
        }
        if(ans==INT_MAX){
            ans=-1;
        }

        return ans;
    }
};