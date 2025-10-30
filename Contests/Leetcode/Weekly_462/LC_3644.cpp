#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        vector<int> req;

        for(int i=0;i<n;i++){
            if(nums[i] != i){
                req.push_back(nums[i]);
            }
        }

        if(req.size()==0){
            return 0;
        }

        int ans=req[0];
        for(int i=1;i<req.size();i++){
            ans=(ans & req[i]);
        }
        return ans;
    }
};