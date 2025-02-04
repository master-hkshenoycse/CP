#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool get_sol(vector<int> &nums,int min_ind){
        int n=nums.size();
        for(int i=1;i<n;i++){
            int nx=(min_ind+i)%n;
            int prev=(min_ind+i-1)%n;
            if(nums[prev]>nums[nx]){
                return 0;
            }
        }
        return 1;
    }
    bool check(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(get_sol(nums,i)){
                return 1;
            }
        }


        
        return 0;
    }
};