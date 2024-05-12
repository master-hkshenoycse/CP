#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int> &cnt){
        int prev=-1;
        for(int i=0;i<26;i++){
            if(cnt[i]==0){
                continue;
            }
            if(prev==-1){
                prev=cnt[i];
            }else{
                if(prev != cnt[i]){
                    return 0;
                }
            }
        }
        return 1;
    }
    int minimumSubstringsInPartition(string s) {
        int n=s.size();
        vector<int> dp(n+1,n+1);
        dp[0]=0;
        
        for(int i=1;i<=n;i++){
            vector<int> freq(26,0);
            for(int j=i;j>=1;j--){
                freq[s[j-1]-'a']++;
                if(check(freq)){
                    dp[i]=min(dp[i],dp[j-1]+1);
                }
            }
        }
        
        return dp[n];
    }
};