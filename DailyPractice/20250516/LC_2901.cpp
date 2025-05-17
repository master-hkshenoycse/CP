#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
            vector<int> dp(n,1),par(n,-1);
            vector<vector<int>> get_ham(n,vector<int> (n,-1));
            
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(words[i].size()==words[j].size()){
                        int c=0;
                        for(int k=0;k<words[i].size();k++){
                            c=c+(words[i][k] != words[j][k]);
                            
                            if(c>2){
                                break;
                            }
                        }
                        
                        get_ham[i][j]=c;
                    }
                }
            }
            
            int ans=0,st=-1;
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    if(groups[i] != groups[j] and get_ham[j][i]==1){
                        dp[i]=max(dp[i],dp[j]+1);
                        if(dp[i]==dp[j]+1){
                            par[i]=j;
                        }
                    }
                }
                
                if(dp[i]>ans){
                    ans=dp[i];
                    st=i;
                }
            }
            
            vector<string> sol;
            
            while(st != -1){
                sol.push_back(words[st]);
                st=par[st];
            }
            
            reverse(sol.begin(),sol.end());
            
            return sol;
            
        
        }
    };