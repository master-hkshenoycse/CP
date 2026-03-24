#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;  

        for(auto e:nums){
            ans=ans+(nums.back()-e);
        }


        return ans;
    }
};