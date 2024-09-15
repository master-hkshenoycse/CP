#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ma=0,n=nums.size(),ans=1;
        for(int i=0;i<n;i++){
            ma=max(ma,nums[i]);
        }
        
        int i=0;
        while(i<n){
            if(nums[i]==ma){
                int c=0,j=i;
                while(j<n and nums[j]==ma){
                    j++;
                    c++;
                }
                i=j;
                ans=max(ans,c);
            }else{
                i++;
            }
        }
        return ans;
    }
};