#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i+1<n;i++){
            if((nums[i]+nums[i+1])%2==0){
                return 0;
            }
        }
        
        return 1;
    }
};