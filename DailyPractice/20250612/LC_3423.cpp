#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxAdjacentDistance(vector<int>& nums) {
            int ans=0,n=nums.size();
            for(int i=0;i<n;i++){
                int j=(i+1)%n;
                ans=max(ans,abs(nums[i]-nums[j]));
            }
            return ans;
        }
    };