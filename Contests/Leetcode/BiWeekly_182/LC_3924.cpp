#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        int lo=0,hi=1e9+5,ret=1e9+5;
        vector<vector<pair<int,int>  >> adj(n+1);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        while(hi>=lo){
            int mid=(hi+lo)/2;

            auto chk = [&]()->bool{
                vector<int> dist(n,1e9);
                set<pair<int,int> > s;

                s.insert({0,source});
                dist[source]=0;

                while(s.size()>0){
                    int v=(*s.begin()).second;
                    s.erase(s.begin());
                    for(auto to:adj[v]){
                        int ex=0;

                        if(to.second>mid)
                            ex++;

                        if(dist[to.first]>dist[v]+ex){
                            dist[to.first]=dist[v]+ex;
                            s.insert({dist[to.first],to.first});
                        }

                    }
                }

                return dist[target]<=k;
            };

            if(chk()){
                ret=min(ret,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }

        }

        if(ret>1e9)
            ret=-1;

        return ret;
    }
};