#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0,n=nums.size(),cnt=0,j=0;

        for(int i=0;i<n;i++){
            cnt+=(nums[i]==0);

            while(cnt>1 and j<=i){
                cnt-=(nums[j]==0);
                j++;
            }

            ans=max(ans,i-j);
        }

        return ans;


    }
};