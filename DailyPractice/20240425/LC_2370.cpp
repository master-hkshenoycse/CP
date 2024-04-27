#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26,0);
        int ans=0;
        for(auto ch:s){
            int tmp=0;
            for(int j=0;j<26;j++){
                if(abs(j-(ch-'a'))<=k){
                    tmp=max(tmp,dp[j]);
                }
            }
            dp[ch-'a']=max(dp[ch-'a'],tmp+1);
            ans=max(ans,dp[ch-'a']);
        }
        return ans;
    }
};