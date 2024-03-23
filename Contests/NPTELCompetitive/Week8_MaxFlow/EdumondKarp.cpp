#include<bits/stdc++.h>
#define ll long long
using namespace std;


//BFS based , finding residual path from s to t and adding the flow of bottlenect edge
//O(v * E^2)
class EdumondKarp{

    public:
    vector<vector<ll> >edge_list;
    vector<vector<ll> > adj_list;
    vector<vector<ll> > parent_list;
    vector<ll> dist;
    ll n;

    EdumondKarp(ll n){
        this->n=n;

        edge_list.clear();
        adj_list.resize(n);
        parent_list.clear();
    }


    void add_edge(ll u,ll v,ll w,ll is_directed){


        //edge from u to v wuth current flow of 0 and capacity w
        edge_list.push_back({v,w,0}) ;
        adj_list[u].push_back(edge_list.size()-1);


        if(is_directed==0){
            w=0;
        }

        //push a back edge from v to u
        edge_list.push_back({u,w,0});
        adj_list[v].push_back(edge_list.size()-1);

    }

    ll send_flow(ll s,ll t){

        ll curr=t;
        ll flow=1e18;
        while(curr != s){
            ll par_idx=parent_list[curr][1];

            flow=min(flow,edge_list[par_idx][1]-edge_list[par_idx][2]);

            curr=parent_list[curr][0];
        }

        curr=t;

        while(curr != s){
            ll par_idx=parent_list[curr][1];
            ll back_edge_idx=(par_idx ^ 1);

            edge_list[par_idx][2]+=flow;//subtract flow from edge
            edge_list[back_edge_idx][2]-=flow;//add the flow to backedge


            curr=parent_list[curr][0];

        }


        return flow;

    }
    bool bfs(ll s,ll t){
        dist.assign(n,-1);
        dist[s]=0;

        queue<int> q;
        q.push(s);

        parent_list.assign(n,{-1,-1});

        while(q.size()>0){
            ll u=q.front();
            q.pop();

            if(u==t){
                break;
            }

            for(auto &idx:adj_list[u]){
                ll v=edge_list[idx][0];
                ll cap=edge_list[idx][1];
                ll flow=edge_list[idx][2];

                if(cap-flow>0 and dist[v]==-1){
                    dist[v]=dist[u]+1;
                    q.push(v);
                    parent_list[v]={u,idx};
                }
            }
        }

        return dist[t] != -1;
    }

    ll get_result(ll s,ll t){
        ll max_flow=0;

        while(bfs(s,t)){
            ll f=send_flow(s,t);
            if(f==0){
                break;
            }

            max_flow+=f;
        }

        return max_flow;
    }

};

int main(){

}