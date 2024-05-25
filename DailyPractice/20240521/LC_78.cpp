#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rec(int ind,vector<int> &curr,vector<int> &nums,vector<vector<int> >&sol){
        if(ind==nums.size()){
            sol.push_back(curr);
            return;
        }

        rec(ind+1,curr,nums,sol);
        curr.push_back(nums[ind]);
        rec(ind+1,curr,nums,sol);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int> >sol;
        rec(0,curr,nums,sol);
        return sol;
    }
};