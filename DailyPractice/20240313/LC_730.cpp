#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod=1e9+7;
    int countPalindromicSubsequences(string s) {
        int n=s.size();

        vector<vector<int> >dp(n+1,vector<int> (n+1,0));
        vector<int> ind(26,-1);

        vector<int> nx_same(n+1,-1),prev_same(n+1,-1);

        for(int i=1;i<=n;i++){
            prev_same[i]=ind[s[i-1]-'a'];
            ind[s[i-1]-'a']=i;
        }

        for(int i=0;i<26;i++){
            ind[i]=-1;
        }

        for(int i=n;i>=1;i--){
            nx_same[i]=ind[s[i-1]-'a'];
            ind[s[i-1]-'a']=i;
        }

        for(int i=1;i<=n;i++){
            dp[i][i]=1;
            if(i+1<=n){
                dp[i][i+1]=2;
            }
        }

        for(int len=3;len<=n;len++){
            for(int st=1;st+len-1<=n;st++){
                int en=st+len-1;
                if(s[st-1]==s[en-1]){
                    dp[st][en]=(2*dp[st+1][en-1])%mod;

                    if(nx_same[st]==en){
                        dp[st][en]=(dp[st][en]+2)%mod;
                    }else if(nx_same[st]==prev_same[en]){
                        dp[st][en]=(dp[st][en]+1)%mod;
                    }else{
                        dp[st][en]=(dp[st][en]-dp[nx_same[st]+1][prev_same[en]-1]+mod)%mod;
                    }   
                }else{
                    dp[st][en]=(dp[st][en-1]+dp[st+1][en])%mod;
                    dp[st][en]=(dp[st][en]-dp[st+1][en-1]+mod)%mod;
                    
                }
            }
        }

        return dp[1][n];

    }
};