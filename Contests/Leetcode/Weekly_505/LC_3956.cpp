#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        ll n=nums.size();
        vector<ll> csum(n+1,0);
        for(ll i=1;i<=n;i++)
            csum[i]=csum[i-1]+nums[i-1];
        
        vector<vector<ll> > dp(n+1,vector<ll> (m+1,-1e18));
        dp[0][0]=0;

        vector<deque<ll> > dq_prev(m+1);

        for(ll i=1;i<=n;i++){
            for(ll k=0;k<=m;k++){                
                dp[i][k]=max(dp[i][k],dp[i-1][k]);

                if(k>0){
                    while(dq_prev[k-1].size()>0 && i-dq_prev[k-1].front()>r)
                        dq_prev[k-1].pop_front();

                    if(dq_prev[k-1].size()>0)
                        dp[i][k]=max(dp[i][k],dp[dq_prev[k-1].front()][k-1]+csum[i]-csum[dq_prev[k-1].front()]);
                }

                if(i-l>=0){
                    while(dq_prev[k].size()>0 && dp[dq_prev[k].back()][k]-csum[dq_prev[k].back()]<=dp[i-l][k]-csum[i-l])
                        dq_prev[k].pop_back();
                    dq_prev[k].push_back(i-l);
                }
            }
        }

        ll ans=-1e18;
        for(ll i=1;i<=m;i++)
            ans=max(ans,dp[n][i]);
        return ans;
    }
};