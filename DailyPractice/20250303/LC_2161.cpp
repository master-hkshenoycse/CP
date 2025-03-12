#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> a;
            int n=nums.size();
            for(int i=0;i<n;i++){
                if(nums[i]<pivot){
                    a.push_back(nums[i]);
                }
            }
            
            for(int i=0;i<n;i++){
                if(nums[i]==pivot){
                    a.push_back(nums[i]);
                }
            }
            
            for(int i=0;i<n;i++){
                if(nums[i]>pivot){
                    a.push_back(nums[i]);
                }
            }
            
            
            return a;
        }
    };