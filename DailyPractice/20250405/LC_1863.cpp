#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int n=nums.size();
            int ans=0;
            for(int i=1;i<(1<<n);i++){
                int xo=0;
                for(int j=0;j<n;j++){
                    if(i & (1<<j))xo=xo ^ nums[j];
                }
                ans+=xo;
            }
            return ans;
        }
    };