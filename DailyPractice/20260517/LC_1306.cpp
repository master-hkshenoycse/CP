#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
                int n=arr.size();
        
        vector<int> adj[n+1],dist(n+1);
        
        for(int i=0;i<n;i++){
            int u=i;
            dist[i]=INT_MAX;
            int v=i+arr[i];
            if(v>=0 and v<n)adj[u].push_back(v);
            
            v=i-arr[i];
            if(v>=0 and v<n)adj[u].push_back(v);
        }
        dist[start]=0;
        queue<int> q;
        q.push(start);
        
        
        while(q.size()){
            int v=q.front();
            q.pop();
            for(int i=0;i<adj[v].size();i++){
                int to=adj[v][i];
                if(dist[to]>dist[v]+1){
                    dist[to]=dist[v]+1;
                    q.push(to);
                }
            }
        }
        
        for(int i=0;i<n;i++) if(dist[i]!=INT_MAX and arr[i]==0)return 1;
        
        return 0;
    }
};