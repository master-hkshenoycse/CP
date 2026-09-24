#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        constexpr ll INF=1e18;
        bool st=0;
        for(auto r:requests)
            if(r==start)
                st=1;
            
        if(!st) requests.push_back(start);
        sort(requests.begin(),requests.end());

        int m=requests.size();
        int sidx=lower_bound(requests.begin(),requests.end(),start)-requests.begin();

        vector<vector<array<ll,2> > > dp(m,vector<array<ll,2> > (m,{INF,INF}));
        dp[sidx][sidx][0]=0;
        dp[sidx][sidx][1]=0;

        for(int len=1;len<m;len++){
            for(int i=0;i+len-1<m;i++){
                int j=i+len-1;
                int rem=m-len;

                //Expand left
                if(i>0){
                    dp[i-1][j][0]=min(dp[i-1][j][0],dp[i][j][0]+1ll*(requests[i]-requests[i-1])*rem);
                    dp[i-1][j][0]=min(dp[i-1][j][0],dp[i][j][1]+1ll*(requests[j]-requests[i-1])*rem);
                }

                //Expand right
                if(j<m-1){
                    dp[i][j+1][1]=min(dp[i][j+1][1],dp[i][j][0]+1ll*(requests[j+1]-requests[i])*rem);
                    dp[i][j+1][1]=min(dp[i][j+1][1],dp[i][j][1]+1ll*(requests[j+1]-requests[j])*rem);
                }
            }
        }

        return min(dp[0][m-1][0],dp[0][m-1][1]);

    }
};