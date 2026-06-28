#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size(),s=0,ans=0;
        for(int i=n-1;i>=0;i--){
            if(i<n-1 && nums[i]*(n-i-1)>s)
                ans++;
            s=s+nums[i];
        }    
        return ans;
    }
};  