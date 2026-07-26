#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int ma_1=INT_MIN;
        int ma_2=INT_MIN;
        int ma_3=INT_MIN;
        
        int mi_1=INT_MAX;
        int mi_2=INT_MAX;
        int mi_3=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(nums[i]>ma_1){
                ma_3=ma_2;
                ma_2=ma_1;
                ma_1=nums[i];
            }else if(nums[i]>ma_2){
                ma_3=ma_2;
                ma_2=nums[i];
            }else if(nums[i]>ma_3){
                ma_3=nums[i];
            }
            
            
            if(nums[i]<mi_1){
                mi_3=mi_2;
                mi_2=mi_1;
                mi_1=nums[i];
            }else if(nums[i]<mi_2){
                mi_3=mi_2;
                mi_2=nums[i];
            }else if(nums[i]<mi_3){
                mi_3=nums[i];
            }
            
            
            
        }
        
        return max(ma_1*ma_2*ma_3,mi_1*mi_2*ma_1);
    }
};