#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        int m=requests.size();
        int total=(1<<m);
        const ll INF=1e18;
        vector<vector<ll> > dp(total,vector<ll> (m,INF));
        
        for(int i=0;i<m;i++){
            ll travel=abs(start-requests[i][1]);
            dp[1<<i][i]=max(travel,(ll)requests[i][0]);
        }

        for(int mask=1;mask<total;mask++){
            for(int last=0;last<m;last++){
                if(!(mask & (1<<last)))
                    continue;
                
                ll currTime=dp[mask][last];
                if(currTime==INF)
                    continue;
                
                for(int next=0;next<m;next++){
                    if(mask & (1<<next))
                        continue;
                    
                    int newMask=mask | (1<<next);
                    ll travel = abs(requests[last][1]-requests[next][1]);
                    ll newTime = currTime+travel;
                    newTime=max(newTime,(ll)requests[next][0]);
                    dp[newMask][next]=min(dp[newMask][next], newTime);
                     
                }
            }
        }
        int full=total-1;
        ll ret=INF;
        for(int last=0;last<m;last++)
            ret=min(ret,dp[full][last]);

        return ret; 
    }
};