#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=2;
        for(int len=3;len<=45;len++){
            for(int i=0;i+len-1<n;i++){

                int x=nums[i],y=nums[i+1];
                int f=1;
                for(int j=i+2;j<=i+len-1;j++){
                    if(nums[j] != x+y){
                        f=0;
                        break;
                    }
                    x=y;
                    y=nums[j];
                }

                if(f){
                    ans=len;
                }
            }
        }
        return ans;




    }
};