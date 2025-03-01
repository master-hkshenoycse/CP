#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n=nums.size();
            vector<int> non_z;
            int cnt_z=0;
            for(int i=0;i+1<n;i++){
                if(nums[i]==nums[i+1]){
                    nums[i]=nums[i]*2;
                    nums[i+1]=0;
                }
            }
            
            for(int i=0;i<n;i++){
                if(nums[i]!=0){
                    non_z.push_back(nums[i]);
                }else{
                    cnt_z++;
                }
            }
            
            
            for(int i=0;i<n;i++){
                nums[i]=0;
            }
            
            int sz=non_z.size();
            for(int i=0;i<sz;i++){
                nums[i]=non_z[i];
            }
            
            return nums;
            
            
        }
    };