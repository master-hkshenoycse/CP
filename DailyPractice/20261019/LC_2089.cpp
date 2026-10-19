#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        vector<int> sol;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                sol.push_back(i);
            }
        }
        return sol;
        
    }
};