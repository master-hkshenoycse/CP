#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> suffix_min(n);
        for(int i=n-1;i>=0;i--){
            suffix_min[i]=nums[i];
            if(i+1<n)
                suffix_min[i]=min(suffix_min[i+1],nums[i]);
        }

        int prefix_max=-1;
        for(int i=0;i<n;i++){
            prefix_max=max(prefix_max,nums[i]);
            if(prefix_max-suffix_min[i]<=k)
                return i;
        }
        return -1;
    }
};