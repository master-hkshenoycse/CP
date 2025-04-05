#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int ans=0,n=nums.size();
            for(int i=0;i+2<n;i++){
                if(nums[i]==0){
                    nums[i]=1-nums[i];
                    nums[i+1]=1-nums[i+1];
                    nums[i+2]=1-nums[i+2];
                    ans++;
                }
            }
            
            if(nums[n-1]==1 and nums[n-2]==1){
                return ans;
            }
            
            return -1;
        }
    };