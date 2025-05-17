#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    void dfs(int v,int p,vector<vector<ll> >  &adj,vector<ll> &par,vector<ll> &in_time,vector<ll> &out_time,int &timer){
        in_time[v]=timer;
        par[v]=p;
        timer++;

        for(auto to:adj[v]){
            if(to == p){
                continue;
            }
            dfs(to,v,adj,par,in_time,out_time,timer);
        }

        out_time[v]=timer;
        timer++;
        
    }

    void upd(ll ind,ll v,ll n,vector<ll> &bit){
        while(ind<=n){
            bit[ind]+=v;
            ind+=(ind & (-ind));
        }
    }
    ll query(ll ind,vector<ll> &bit){
        ll ret=0;
        while(ind>0){
            ret=ret+bit[ind];
            ind-=(ind & (-ind));
        }
        return ret;
    }
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<ll> > adj(n+1);
        vector<ll> par(n+1),in_time(n+1),out_time(n+1),bit_(4*n+5,0);
        map<pair<int,int>,int >edge_wt; 
        
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int timer=1;
        dfs(1,-1,adj,par,in_time,out_time,timer);

        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            edge_wt[{u,v}]=w;
            
            if(par[u]==v){
                upd(in_time[u],w,3*n,bit_);
                upd(out_time[u],-w,3*n,bit_);
            }else{
                upd(in_time[v],w,3*n,bit_);
                upd(out_time[v],-w,3*n,bit_);
            }
        }

        vector<int> ret;
        for(auto q:queries){
            if(q[0]==2){
                ret.push_back(query(in_time[q[1]],bit_));
            }else{
                int u=q[1];
                int v=q[2];
                int w=q[3];
                int w_;

                if(edge_wt.find({u,v}) != edge_wt.end()){
                    w_=edge_wt[{u,v}];
                    edge_wt[{u,v}]=w;
                }else{
                    w_=edge_wt[{v,u}];
                    edge_wt[{v,u}]=w;
                }

                if(par[u]==v){
                    upd(in_time[u],-w_,3*n,bit_);
                    upd(out_time[u],w_,3*n,bit_);

                    upd(in_time[u],w,3*n,bit_);
                    upd(out_time[u],-w,3*n,bit_);
                    
                }else{
                    upd(in_time[v],-w_,3*n,bit_);
                    upd(out_time[v],w_,3*n,bit_);

                    upd(in_time[v],w,3*n,bit_);
                    upd(out_time[v],-w,3*n,bit_);
                }
        
            }
        }

        return ret;
    
    }
};