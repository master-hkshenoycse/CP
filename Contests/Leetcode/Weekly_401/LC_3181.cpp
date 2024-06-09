#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        int n=rewardValues.size();

        vector<int> dp(50001,0);
        

        for(int i=0;i<n;i++){

            if(i>0 and rewardValues[i]==rewardValues[i-1]){
                continue;
            }

            int val=rewardValues[i];
            int lim=min(val,rewardValues.back()-val);

            for(int x=0;x<lim;x++){
                dp[val+dp[x]]=val+dp[x];
            }
        }

        int ans=0;
        for(int i=0;i<=50000;i++){
            ans=max(ans,dp[i]);
        }
        ans+=rewardValues.back();
        return ans;
        
    }
};