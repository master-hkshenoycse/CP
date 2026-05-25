#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> adj[n];
        vector<int> dp(n,1),in_deg(n,0);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(j-i>d){
                    break;
                }
                if(arr[i]<=arr[j]){
                    break;
                }

                adj[i].push_back(j);
                in_deg[j]++;
            }

            for(int j=i-1;j>=0;j--){
                if(i-j>d){
                    break;
                }
                if(arr[i]<=arr[j]){
                    break;
                }

                adj[i].push_back(j);
                in_deg[j]++;
            }

        }

        queue<int> q;

        for(int i=0;i<n;i++){
            if(in_deg[i]==0){
                q.push(i);
            }
        }

        int ans=0;
        while(q.size()>0){
            int v=q.front();
            q.pop();
            ans=max(ans,dp[v]);

            for(auto to:adj[v]){
                dp[to]=max(dp[to],dp[v]+1);
                in_deg[to]--;

                if(in_deg[to]==0){
                    q.push(to);
                }
            }
        }

        return ans;
    }
};