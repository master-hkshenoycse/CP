#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            while(i != nums[i]-1){
                if(nums[nums[i]-1] != nums[i]){
                    swap(nums[nums[i]-1],nums[i]);
                }else{
                    break;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(i != nums[i]-1){
                return nums[i];
            }
        }
        return 0;
        
        
    }
};