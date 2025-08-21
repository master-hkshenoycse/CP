#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n+1,0);
        double s=0.0;

        dp[0]=1.00;
        if(k>0.0){
            s=1.0;
        }

        for(int i=1;i<=n;i++){
            dp[i]=s/(maxPts*1.00);

            if(i<k){
                s=s+dp[i];
            }
            if(i-maxPts>=0 and i-maxPts<k){
                s-=dp[i-maxPts];
            }
        }



        double ans=0.0;
        for(int i=k;i<=n;i++){
            ans=ans+dp[i];
        }
        return ans;
    }
};