#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string triangleType(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            if(nums[2]>=nums[0]+nums[1]){
                return "none";
            }
            if(nums[0]==nums[2]){
                return "equilateral";
            }
            
            if(nums[1]==nums[0] or nums[1]==nums[2]){
                return "isosceles";
            }
            
            return "scalene";
        }
    };