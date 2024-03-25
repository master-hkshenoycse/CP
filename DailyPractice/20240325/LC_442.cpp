#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> sol;
        for(int i=0;i<n;i++){
            int x=abs(nums[i]);
            if(nums[x-1]<0){//this is repeating
                sol.push_back(abs(nums[i]));
            }
            nums[x-1]*=-1;
        }
        return sol;
    }
};