#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int gc=__gcd(nums[0],nums[nums.size()-1]);
        return gc;
    }
};