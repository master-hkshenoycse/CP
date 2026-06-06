#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        set<int> help;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] != target[i])
                help.insert(nums[i]);
        }
        return help.size();
    }
};