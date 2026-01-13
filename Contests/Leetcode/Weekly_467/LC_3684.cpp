#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> ret;
        for(int i=n-1;i>=0;i--){
            if(i+1==n || nums[i] != nums[i+1]){
                if(ret.size()<k)ret.push_back(nums[i]);
            }
        }
        
        return ret;
    }
};