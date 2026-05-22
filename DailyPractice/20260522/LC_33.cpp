#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int target_big=(target>=nums[0]);
        int lo=0,hi=n-1;

        while(hi>=lo){
            int mid=(hi+lo)/2;

            if(nums[mid]==target){
                return mid;
            }

            //cout<<lo<<" "<<hi<<" "<<mid<<endl;

            int mid_big=(nums[mid]>=nums[0]);

            if(mid_big==target_big){
                if(nums[mid]>target){
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }

            }else{

                if(target_big){
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
        }

        return -1;
        
    }
};