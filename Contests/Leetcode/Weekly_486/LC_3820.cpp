#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void get_dist(vector<vector<int> >&adj,vector<int> &ds,int start){
        ds[start]=0;
        queue<int> q;
        q.push(start);

        while(q.size()>0){
            int v=q.front();
            q.pop();

            for(auto to:adj[v]){
                if(ds[to]>ds[v]+1){
                    q.push(to);
                    ds[to]=ds[v]+1;
                }
            }
        }
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int> > adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }   

        vector<int> dx(n,INT_MAX),dy(n,INT_MAX),dz(n,INT_MAX);

        get_dist(adj,dx,x);
        get_dist(adj,dy,y);
        get_dist(adj,dz,z);


        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> d={dx[i],dy[i],dz[i]};
            sort(d.begin(),d.end());
            if(d[2]*1ll*d[2]*1ll==d[0]*1ll*d[0]*1ll+d[1]*1ll*d[1]*1ll)
                ans++;
        }
        return ans;
    }
};