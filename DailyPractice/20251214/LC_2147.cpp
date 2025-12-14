#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfWays(string corridor) {
        int n=corridor.size();
        vector<int> c_dp(n+2,0);
        vector<int> dp(n+1,0);
        c_dp[0]=1;

        int cs=0,mod=1e9+7;

        for(int i=0;i<n;i++){
            cs=cs+(corridor[i]=='S');
            if(cs>=2){
                dp[i]=c_dp[cs-2];
                c_dp[cs]=(c_dp[cs]+c_dp[cs-2])%mod;
            }
        }

        return dp[n-1];
        
    }
};