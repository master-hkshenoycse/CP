#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> doBFS(int v,vector<int> &edges){
            int n=edges.size();
            vector<int> dp(n,-1);
            
            dp[v]=0;
            queue<int> q;
            q.push(v);
            
            while(q.size()>0){
                int curr=q.front();
                q.pop();
                
                int nx=edges[curr];
    
                if(nx>-1 and dp[nx] == -1){
                    dp[nx]=dp[curr]+1;
                    q.push(nx);
                }
                
            }
            return dp;
        }    
        int closestMeetingNode(vector<int>& edges, int node1, int node2) {
            int n=edges.size();
            vector<int> bfsNode1=doBFS(node1,edges);
            vector<int> bfsNode2=doBFS(node2,edges);
            
            int dist_MIN=INT_MAX;
            for(int i=0;i<n;i++){
                if(bfsNode1[i]!=-1 and bfsNode2[i]!=-1){
                    dist_MIN=min(dist_MIN,max(bfsNode1[i],bfsNode2[i]));
                }
            }
            
            if(dist_MIN==INT_MAX){
                return -1;
            }
            
            for(int i=0;i<n;i++){
                if(bfsNode1[i]!=-1 and bfsNode2[i]!=-1 and max(bfsNode1[i],bfsNode2[i])==dist_MIN){
                    return i;
                }
            }
            return -1;
            
            
        }
    };