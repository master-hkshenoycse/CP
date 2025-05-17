#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
            int n=words.size(),ans=0,st=0;
            vector<int> dp(n,1),par(n,-1);
            
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    if(groups[i] != groups[j]){
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