#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),ops=0;
        
        for(int i=0;i<n;i++){
            if((nums[i]+ops)%2==0){
                ops++;
            }
        }
        return ops;
    }
};