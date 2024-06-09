#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        
        int ans=0;
        sort(rewardValues.begin(),rewardValues.end());
        
        vector<int> dp(2005,0);
        dp[0]=1;

        for(auto r:rewardValues){
            for(int j=2000;j>=0;j--){
                if(dp[j]==1 and j<r){
                    if(j+r<=2000){
                        dp[j+r]=1;   
                    }
                    ans=max(ans,j+r);
                }
            }
        }
        


        return ans;
    }
};