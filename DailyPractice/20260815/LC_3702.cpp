#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xo=0,n=nums.size(),cnt_zero=0;
        for(auto e:nums){
            xo=(xo ^ e);
            if(e==0){
                cnt_zero++;
            }
        }

        if(xo>0){
            return n;
        }

        if(cnt_zero==n){
            return 0;
        }

        return n-1;
    }
};