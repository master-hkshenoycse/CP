#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll par[100005][20],depth[100005],dist[100005];
    vector<vector<ll> > adj[100005];

    void dfs(int v,int p){
        if(p != -1){
            depth[v]=(depth[p]+1);
            par[v][0]=p;
        }

        for(int j=1;j<20;j++){
            if(par[v][j-1] != -1){
                par[v][j]=par[par[v][j-1]][j-1];
            }
        }

        for(auto to:adj[v]){
            if(to[0] == p){
                continue;
            }
            dist[to[0]]=dist[v]+to[1];
            dfs(to[0],v);
        }
    }
    int get_lca(int x,int y){
        if(depth[x] > depth[y]){
            swap(x,y);
        }

        int diff = depth[y]-depth[x];

        for(int i=19;i>=0;i--){
            if(diff & (1<<i)){
                y=par[y][i];
            }
        }

        if(x==y){
            return x;
        }

        for(ll i=19;i>=0;i--){
            if(par[x][i] != par[y][i]){
                x=par[x][i];
                y=par[y][i];
            }
        }
        
        return par[x][0];
    }

    int find_vertex_at_d(int v,int d){
        //cout<<v<<" "<<d<<" "<<__func__<<endl;
        for(int i=19;i>=0;i--){
            if(d & (1<<i)){
                v=par[v][i];
            }
        }
        return v;
    }


    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
        for(int i=0;i<n;i++){
            adj[i].clear();
            dist[i]=0;
            depth[i]=0;
            for(int j=0;j<20;j++){
                par[i][j]=-1;
            }
        }

        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        dfs(0,-1);

        vector<int> ret;

        for(auto q:queries){
            int x = q[0];
            int y = q[1];
            int lca = get_lca(x,y);
            
            ll req_dist = (dist[x]+dist[y]-2*dist[lca]+1)/2;
            //cout<<req_dist<<endl;    
            int res;

            if(dist[x]>dist[y]){
                int lo=0,hi=depth[x]-depth[lca];
                int res_depth = hi;
                while(hi>=lo){
                    int mid = (hi+lo)/2;
                    int vert = find_vertex_at_d(x,mid);

                    if((dist[x]-dist[vert]) >= req_dist){
                        res_depth = min(res_depth,mid);
                        hi=mid-1;
                    }else{
                        lo=mid+1;
                    }
                }

                res = find_vertex_at_d(x,res_depth);
            }else{
                int d_right = depth[y]-depth[lca];
                int lo=0,hi=d_right,res_depth=d_right;

                while(hi>=lo){
                    int mid = (hi+lo)/2;
                    int vert = find_vertex_at_d(y, d_right-mid);
                    if((dist[x]-dist[lca]+dist[vert]-dist[lca]) >= req_dist){
                        res_depth = min(res_depth,mid);
                        hi=mid-1;
                    }else{
                        lo=mid+1;
                    }
                }

                res = find_vertex_at_d(y,d_right-res_depth);
            }
            ret.push_back(res);
        }

        return ret;

    }
};