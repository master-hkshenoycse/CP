#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod =1e9+7;
    ll modpow(ll a,ll n){
        if(n<0){
            return 0;
        }
        ll res=1;
        while(n>0){
            if(n%2){
                res=(res*a)%mod;
            }
            n/=2;
            a=(a*a)%mod;
        }
        return res;
    }
    void dfs(ll v,ll p,vector<vector<ll> >&adj,vector<vector<ll> >&lca,vector<ll> &depth){
        if(p>0){
            depth[v]=depth[p]+1;
            lca[v][0]=p;
        }

        for(ll i=1;i<=20;i++){
            if(lca[v][i-1] != -1){
                lca[v][i]=lca[lca[v][i-1]][i-1];
            }
        }

        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            dfs(to,v,adj,lca,depth);
        }
    }
    ll get_lca(ll x,ll y,vector<ll> &depth,vector<vector<ll> >&lca){
        if(depth[x]>depth[y]){
            swap(x,y);
        }

        ll diff = depth[y]-depth[x];
        for(ll i=20;i>=0;i--){
            if(diff & (1ll<<i)){
                y=lca[y][i];
            }
        }

        if(x==y){
            return x;
        }

        for(ll i=20;i>=0;i--){
            if(lca[x][i] != lca[y][i]){
                x=lca[x][i];
                y=lca[y][i];
            }
        }

        return lca[x][0];
    }

    ll get_dist(ll x,ll y,vector<ll> &depth,vector<vector<ll> >&lca){
         ll lc=get_lca(x,y,depth,lca);
        return depth[x]+depth[y]-2*depth[lc];
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        ll n=edges.size()+1;
        vector<vector<ll> > adj(n+1);
        vector<vector<ll> > lca(n+1,vector<ll> (21,-1));
        vector<ll> depth(n+1,0);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1,-1,adj,lca,depth);

        vector<int> sol;

        for(auto q:queries){
            int x=q[0];
            int y=q[1];
            int d=get_dist(x,y,depth,lca);
            sol.push_back(modpow(2,d-1));
            
        }

        return sol;
        
        
        
    }
};