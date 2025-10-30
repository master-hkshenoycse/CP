#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check_increase(vector<int> &nums,int st,int en){
        for(int i=st+1;i<=en;i++){
            if(nums[i]<=nums[i-1]){
                return 0;
            }
        }
        return 1;
    }
    bool check_decrease(vector<int> &nums,int st,int en){
        for(int i=st+1;i<=en;i++){
            if(nums[i]>=nums[i-1]){
                return 0;
            }
        }
        return 1;
    }
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n-1;j++){
                if(check_increase(nums,0,i) && check_decrease(nums,i,j) && check_increase(nums,j,n-1)){
                    return 1;
                }
            }
        }

        return 0;
    }
};