#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            int n=str1.size(),m=str2.size();
            vector<vector<int> > dp(n+1,vector<int> (m+1,1e9));
            dp[0][0]=0;
    
            for(int i=0;i<=n;i++){
                for(int j=0;j<=m;j++){
                    if(i==0 && j==0){
                        continue;
                    }else if(i==0){
                        dp[i][j]=j;
                    }else if(j==0){
                        dp[i][j]=i;
                    }else{
    
                        if(str1[i-1]==str2[j-1]){
                            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
                        }else{
                            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                        }
                    }
                }
            }
    
            string superseq;
            int row=n,col=m;
            while(row>0 && col>0){
                if(str1[row-1]==str2[col-1]){
                    superseq+=str1[row-1];
                    row--;
                    col--;
                }else if(dp[row-1][col] <dp[row][col-1]){
                    superseq+=str1[row-1];
                    row--;
                }else{
                    superseq+=str2[col-1];
                    col--;
                }
            }
    
            while(row>0){
                superseq+=str1[row-1];
                row--;
            }
    
            while(col>0){
                superseq+=str2[col-1];
                col--;
            }
    
        
            reverse(superseq.begin(),superseq.end());
            return superseq;
    
    
    
        }
    };