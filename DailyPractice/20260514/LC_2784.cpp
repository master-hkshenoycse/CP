#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int base=n-1;
        for(int i=0;i<n-1;i++){
            if(nums[i] != i+1){
                return 0;
            }
        }
        
        if(nums[n-1]!=base){
            return 0;
        }
        
        return 1;
    }
};