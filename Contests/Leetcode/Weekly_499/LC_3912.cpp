#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int pref_max=-1,n=nums.size();
        vector<int> suff_max(n+1,-1);
        for(int i=n-1;i>=0;i--)
            suff_max[i]=max(suff_max[i+1],nums[i]);
        
        vector<int> ret;
        
        for(int i=0;i<n;i++){
            if(nums[i]>pref_max || nums[i]>suff_max[i+1])
                ret.push_back(nums[i]);
            pref_max=max(pref_max,nums[i]);
        }

        return ret;
    }
};