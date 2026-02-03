#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int ret=0,m=1;
        for(auto e:nums){
            ret=ret+m*e;
            m=m*-1;
        }

        return ret;
    }
};