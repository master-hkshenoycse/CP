#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_sod(int n){
        int s=0;
        while(n>0){
            s+=(n%10);
            n/=10;
        }
        return s;
    }
    int countArrays(vector<int>& digitSum) {
        vector<int> dig_sum[51];
        for(int i=0;i<=5000;i++)
            dig_sum[get_sod(i)].push_back(i);
        
        int mod=1e9+7;
        int n=digitSum.size();
        vector<vector<int> >dp(n+1,vector<int> (5001,0));
        for(int j=0;j<=5000;j++)
            dp[0][j]=1;

        for(int i=1;i<=n;i++){
            for(auto d:dig_sum[digitSum[i-1]]){
                dp[i][d]=(dp[i][d]+dp[i-1][d])%mod;
            }

            for(int j=1;j<=5000;j++){
                dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
            }   
        }

        return dp[n][5000];

    }
};