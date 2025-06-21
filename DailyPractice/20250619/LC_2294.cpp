#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int partitionArray(vector<int>& nums, int k) {
            sort(nums.begin(),nums.end());
            int i=0,ans=0,n=nums.size();
            
            while(i<n){
                int j=i;
                ans++;
                
                while(j<n and nums[j]-nums[i]<=k){
                    j++;
                }
                
                i=j;
            }
            
            return ans;
        }
    };