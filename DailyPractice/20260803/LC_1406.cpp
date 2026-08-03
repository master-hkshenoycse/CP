#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[2][50005];
    int memo[2][50005];

    int solve_dp(int index,int p,vector<int>& stoneValue){
        int n=stoneValue.size();
        if(index==n){
            return 0;
        }

        if(memo[p][index]){
            return dp[p][index];
        }

        memo[p][index]=1;
        int res=INT_MIN;
        if(p){
            res=INT_MAX;
        }
        int s=0;

        for(int i=0;i<3;i++){
            if(index+i>=n){
                break;
            }
            s=s+stoneValue[index+i];
            
            if(p){
                res=min(res,solve_dp(index+i+1,1-p,stoneValue));
            }else{
                res=max(res,s+solve_dp(index+i+1,1-p,stoneValue));
            }
        }

        return dp[p][index]=res;
    }
    string stoneGameIII(vector<int>& stoneValue) {

        int value=solve_dp(0,0,stoneValue);
        int tot_sum=0;
        for(auto e:stoneValue){
            tot_sum+=e;
        }

        if(value>tot_sum-value){
            return "Alice";
        }

        if(value<tot_sum-value){
            return "Bob";
        }


        return "Tie";
    }
};