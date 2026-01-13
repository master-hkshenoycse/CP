#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ret=0;
        for(auto e:nums){
            if(e%2==0)ret=(ret | e);
        }
        return ret;
    }
};