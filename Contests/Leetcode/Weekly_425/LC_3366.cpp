#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[105][105][105];
    int solve(int ind,int op1,int op2,vector<int> &a,int k){
        if(ind==a.size()){
            return 0;
        }
        
        if(dp[ind][op1][op2] != -1){
            return dp[ind][op1][op2];
        }

        int res=a[ind]+solve(ind+1,op1,op2,a,k);
        if(op1>0){
            res=min(res,(a[ind]+1)/2+solve(ind+1,op1-1,op2,a,k));
        }

        if(op2>0 and a[ind]>=k){
            res=min(res,a[ind]-k+solve(ind+1,op1,op2-1,a,k));
        }

        if(op1>0 and op2>0){
            
            if(a[ind]>=k)res=min(res,(a[ind]-k+1)/2+solve(ind+1,op1-1,op2-1,a,k));
            int r=(a[ind]+1)/2;
            if(r>=k){
                res=min(res,r-k+solve(ind+1,op1-1,op2-1,a,k));
            }
        }

        return dp[ind][op1][op2]=res;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,op1,op2,nums,k);
    }
};