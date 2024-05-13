#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lim;
    int solve_dp(int mask,int prev,vector<vector<int> > &dp,vector<vector<int> > &nxt_value,vector<int> &nums,int first){
        if(mask==lim-1){
            return abs(prev-nums[first]);
        }

        if(dp[mask][prev] != -1){
            return dp[mask][prev];
        }

        int res=INT_MAX;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(mask & (1<<i)){
                continue;
            }

            int cost=abs(prev-nums[i])+solve_dp(mask| (1<<i),i,dp,nxt_value,nums,first);

            if(cost < res){
                res=cost;
                nxt_value[mask][prev]=i;
            }
        }


        return dp[mask][prev]=res;

    }
    vector<int> findPermutation(vector<int>& nums) {
        int n=nums.size();
        lim=(1<<n);

        vector<vector<int> > dp(lim,vector<int> (n,-1));
        vector<vector<int> > nxt_value(lim,vector<int> (n,-1));
        
        int cost=INT_MAX;
        vector<int> sol;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<lim;j++){
                for(int k=0;k<n;k++){
                    dp[j][k]=-1;
                    nxt_value[j][k]=-1;
                }
            }

            int curr_cost=solve_dp(1<<i,i,dp,nxt_value,nums,i);

            
            //cout<<i<<" "<<curr_cost<<endl;
            if(cost > curr_cost){
                cost=curr_cost;
                int start=i;

                sol.clear();
                int mask=0;
                while(sol.size()<n){
                    sol.push_back(start);
                    mask=(mask | (1<<start));
                    start=nxt_value[mask][start];
                }
                   
            }
        }

        
        return sol;



    }
};