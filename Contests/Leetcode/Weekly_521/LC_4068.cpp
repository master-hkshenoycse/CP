#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
        ll n=meetings.size();
        sort(meetings.begin(),meetings.end());
        vector<ll> dp(n,0);

        priority_queue<pair<int,int> ,vector<pair<int,int> >, greater<pair<int,int> > >pq_end;
        priority_queue<ll> pq_dps;
        ll ans=0;

        for(ll i=0;i<n;i++){
            dp[i]=meetings[i][2];

            while(pq_end.size()>0 && meetings[pq_end.top().second][1]<=meetings[i][0]){
                pq_dps.push(dp[pq_end.top().second]-meetings[pq_end.top().second][1]);
                pq_end.pop();
            }

            if(pq_dps.size()>0)
                dp[i]=max(dp[i],meetings[i][2]+pq_dps.top()+meetings[i][0]);
            
            pq_end.push({meetings[i][1],i});
            
            ans=max(ans,dp[i]);
        }

        return ans;

    }
};