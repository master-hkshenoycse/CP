#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mod=0;
        for(auto e:nums){
            mod=(mod+e)%k;
        }

       
        return mod;
    }
};