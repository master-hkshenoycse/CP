#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int ans=0,n=nums.size();
            for(int i=0;i+2<n;i++){
                if((nums[i]+nums[i+2])*2==nums[i+1]){
                    ans++;
                }
            }
            return ans;
        }
    };