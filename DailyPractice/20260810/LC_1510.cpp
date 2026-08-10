#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,0);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                //cout<<i<<" "<<(j*j)<<endl;
                if(dp[i-j*j]==0){
                    dp[i]=1;
                }
            }
        }
        
        return dp[n];
    }
};