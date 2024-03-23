#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),s=0;
        s=(n*n+n)/2;
        
        for(auto e:nums){
            s-=e;
        }
        return s;
    }
};