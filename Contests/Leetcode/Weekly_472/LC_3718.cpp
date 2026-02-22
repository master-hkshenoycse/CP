#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        set<int> nums_set(nums.begin(),nums.end());

        for(int i=k;i<=10000;i+=k){
            if(nums_set.find(i) == nums_set.end())
                return i;
        }

        return -1;

    }
};