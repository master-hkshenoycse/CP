#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> >dp(n+1,vector<int> (m+1,0));
        dp[0][0]=0;
        int ans=0;
        
        for(auto s:strs){
            int c1=0,c0=0,l=s.size();
            for(auto ch:s){
                c1+=(ch=='1');
                c0+=(ch=='0');
            }
            
            vector<vector<int> >tmp(n+1,vector<int> (m+1,0));
            
            for(int i=0;i<=n;i++){
                for(int j=0;j<=m;j++){
                    if(i+c1<=n and j+c0<=m){
                        tmp[i+c1][j+c0]=max(tmp[i+c1][j+c0],dp[i][j]+1);
                    }
                }
            } 
            
            for(int i=0;i<=n;i++){
                for(int j=0;j<=m;j++){
                    dp[i][j]=max(tmp[i][j],dp[i][j]);
                    ans=max(ans,dp[i][j]);
                }
            }        
        }
        
        return ans;
        
    }
};