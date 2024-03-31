
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod=1e9+7;
    int dp[51][51][51][51];
    //states are index,length,and two index(x,y) which contain the least value
    int solve(int i,int n,int k,int x,int y,vector<int> &nums){
        if(k==0){
            int min_diff=nums[y]-nums[x];
            return nums[y]-nums[x];
        }

        if(i>=n){
            return 0;
        }

        if(dp[i][k][x][y] != -1){
            return dp[i][k][x][y];
        }

        long long sum=0;
        for(int j=i;j<n;j++){
            int prev=i-1;
            if(prev==-1){
                sum=sum+solve(j+1,n,k-1,x,y,nums);
                sum%=mod;
            }else{
                int val=nums[j]-nums[prev];
                int min_diff=nums[y]-nums[x];

                if(val<min_diff){
                    sum=(sum+solve(j+1,n,k-1,prev,j,nums))%mod;
                }else{
                    sum=(sum+solve(j+1,n,k-1,x,y,nums))%mod;
                }
            }
        }

        return dp[i][k][x][y]=sum;
    }    
    int sumOfPowers(vector<int>& nums, int k) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        return solve(0,n,k,0,n-1,nums);
    }
};