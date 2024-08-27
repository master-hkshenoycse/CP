#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        int n=nums.size();
        while(k--){
            int min_val=INT_MAX,min_ind=-1;
            for(int i=0;i<n;i++){
                if(nums[i]<min_val){
                    min_val=nums[i];
                    min_ind=i;
                }
            }

            nums[min_ind]*=multiplier;
        }

        return nums;
    }
};