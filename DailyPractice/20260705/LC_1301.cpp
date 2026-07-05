#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        int mod=1e9+7;
        vector<vector<int> > dp(n,vector<int> (n,0)),ways_(n,vector<int> (n,0));
        dp[n-1][n-1]=0;
        ways_[n-1][n-1]=1;

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){

                if(board[i][j]=='X' or board[i][j]=='S'){
                    continue;
                }

                int max_poss=0,ways_poss=0;
                if(i+1<n)
                    max_poss=max(max_poss,dp[i+1][j]);

                if(j+1<n)
                    max_poss=max(max_poss,dp[i][j+1]);
 
                if(i+1<n && j+1<n)
                    max_poss=max(max_poss,dp[i+1][j+1]);
                
                if(i+1<n && max_poss==dp[i+1][j])
                    ways_poss=(ways_poss+ways_[i+1][j])%mod;

                if(j+1<n && max_poss==dp[i][j+1])
                    ways_poss=(ways_poss+ways_[i][j+1])%mod;
                
                if(i+1<n && j+1<n && max_poss==dp[i+1][j+1])
                    ways_poss=(ways_poss+ways_[i+1][j+1])%mod;
                
                dp[i][j]=max_poss;
                ways_[i][j]=ways_poss;

                if(board[i][j]>='1' && board[i][j]<='9')
                    dp[i][j]=dp[i][j]+(board[i][j]-'0');

            }
        }

        if(ways_[0][0]==0)
            dp[0][0]=0;
            
        return {dp[0][0],ways_[0][0]};

    }
};