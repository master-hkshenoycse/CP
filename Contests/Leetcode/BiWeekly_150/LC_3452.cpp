#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int sumOfGoodNumbers(vector<int>& nums, int k) {
            int ans=0,n=nums.size();
    
            for(int i=0;i<n;i++){
                int f=0;
                if(i+k<n and nums[i]<=nums[i+k]){
                    f++;
                }
    
                if(i-k>=0 and nums[i]<=nums[i-k]){
                    f++;
                }
                
                if(f==0){
                    ans=ans+nums[i];
                }
            }
    
            return ans;
        }
    };