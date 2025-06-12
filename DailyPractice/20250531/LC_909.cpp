#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int snakesAndLadders(vector<vector<int>>& board) {
            int n=board.size();
    
            vector<int>dp(n*n+1,INT_MAX);
            dp[1]=0;
    
            int ind=1,c=0;
            map<int,int> help;
            for(int i=n-1;i>=0;i--){
    
                if(c==0){
                    for(int j=0;j<n;j++){
                        if(board[i][j] != -1){
                            help[ind]=board[i][j];
                        }
                        ind++;
                    }
                    
                }else{
                    for(int j=n-1;j>=0;j--){
                        if(board[i][j] != -1){
                            help[ind]=board[i][j];
                        }
                        ind++;
                    }
                }
                c=1-c;
            }
    
            queue<int> q;
            q.push(1);
    
            while(q.size()>0){
                int x=q.front();
                q.pop();
    
                for(int i=1;i<=6;i++){
    
                    if(x+i>n*n){
                        break;
                    }
                    
    
                    if(help.find(x+i)== help.end()){
                        if(dp[x+i]>dp[x]+1){
                            dp[x+i]=dp[x]+1;
                            q.push(x+i);
                        }
                    }else{
                        if(dp[help[x+i]]>dp[x]+1){
                            dp[help[x+i]]=dp[x]+1;
                            q.push(help[x+i]);
                        }
                    }
                }
            }
    
            if(dp[n*n]==INT_MAX){
                dp[n*n]=-1;
            }
    
            return dp[n*n];
        }
    };