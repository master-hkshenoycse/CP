#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[25][25][2];
    int memo[25][25][2];
    int get_max(vector<int> &nums,int l,int r,int ty){
        if(r<l){
            return 0;
        }

        if(l==r){
            if(ty==0){
                return nums[l];
            }else{
                return 0;
            }
        }

        if(r==l+1){
            if(ty==0){
                return max(nums[l],nums[r]);
            }else{
                return min(nums[l],nums[r]);
            }
        }

        if(memo[l][r][ty]){
            return dp[l][r][ty];
        }

        memo[l][r][ty]=1;
        int res=0;

        if(ty==0){
            res=max(res,nums[l]+get_max(nums,l+1,r,1));
            res=max(res,nums[r]+get_max(nums,l,r-1,1));
        }else{
            res=INT_MAX;
            res=min(get_max(nums,l+1,r,0),get_max(nums,l,r-1,0));

        }

        return dp[l][r][ty]=res;

        
    }
    bool predictTheWinner(vector<int>& nums) {
        int tot=0,n=nums.size();
        for(auto e:nums){
            tot=tot+e;
        }

        int a_max=get_max(nums,0,n-1,0);
        int b_max=tot-a_max;

        return a_max>=b_max;



    }
};