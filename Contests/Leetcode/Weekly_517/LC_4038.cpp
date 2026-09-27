#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,int> fs_,ls_,freq_;
        for(int i=0;i<nums.size();i++){
            freq_[nums[i]]++;
            ls_[nums[i]]=i;
            if(fs_.find(nums[i])==fs_.end())
                fs_[nums[i]]=i;
        }

        int ans=0;
        for(auto it:freq_){
            if(it.second == ls_[it.first]-fs_[it.first]+1)
                ans++;
        }
        return ans;
    }
};