#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxSubstrings(string word) {
            int n=word.size();
            vector<int> dp(n+1,0);
    
            dp[0]=0;
            vector<vector<int> > char_index(26);
            for(int i=1;i<=n;i++){
                dp[i]=dp[i-1];
                int ch=word[i-1]-'a';
                int sz=char_index[ch].size();
                for(int j=sz-1;j>=0;j--){
                    if(i-char_index[ch][j]+1>=4){
                        dp[i]=max(dp[i],dp[char_index[ch][j]-1]+1);
                        break;
                    }
                }
                char_index[ch].push_back(i);
            }
    
            return dp[n];
            
        }
    };