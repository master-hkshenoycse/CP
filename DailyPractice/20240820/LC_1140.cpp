#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[101][101][2];
    int solve(int ind,int m,int ch,vector<int> &piles){
        if(ind==piles.size()){
            return 0;
        }

        if(dp[ind][m][ch] != -1){
            return dp[ind][m][ch];
        }

        int res;
        if(ch==0){
            res=INT_MIN;
            int sum=0,len=0;
            for(int i=ind;i<piles.size();i++){
                len++;
                if(len>2*m){
                    break;
                }
                sum=sum+piles[i];
                res=max(res,sum+solve(i+1,max(m,len),1-ch,piles));
            }
        }else{
            res=INT_MAX;
            int sum=0,len=0;
            for(int i=ind;i<piles.size();i++){
                len++;
                if(len>2*m){
                    break;
                }
                sum=sum+piles[i];
                res=min(res,solve(i+1,max(m,len),1-ch,piles));
            }

        }

        return dp[ind][m][ch]=res;


    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,1,0,piles);

    }
};