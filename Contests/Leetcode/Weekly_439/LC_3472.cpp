#include<bits/stdc++.h>
using namespace std;
int dp[205][205][205];
class Solution {
public:
    int max_palin(int st,int en,int op,string &s){
        
        if(st>en){
            return 0;
        }
        
        if(st==en){
            return 1;
        }
        

        
        if(dp[st][en][op] != -1){
            return dp[st][en][op];
        }
        
        int ret=max_palin(st+1,en,op,s);
        ret=max(ret,max_palin(st,en-1,op,s));
        
        if(s[st]==s[en]){
            ret=max(ret,2+max_palin(st+1,en-1,op,s));
        }else{
            int req=min(26-abs(s[st]-s[en]),abs(s[st]-s[en]));
            if(req<=op){
                ret=max(ret,2+max_palin(st+1,en-1,op-req,s));
            }
        }
        
        return dp[st][en][op]=ret;
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int o=0;o<=k;o++){
                    dp[i][j][o]=-1;
                }
            }
        }
        
        return max_palin(0,n-1,k,s);
    }
};