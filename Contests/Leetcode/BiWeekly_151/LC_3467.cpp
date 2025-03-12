#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> transformArray(vector<int>& nums) {
            int n=nums.size();
            for(int i=0;i<n;i++){
                nums[i]=(nums[i]%2);
            }
            sort(nums.begin(),nums.end());
            return nums;
        }
    };