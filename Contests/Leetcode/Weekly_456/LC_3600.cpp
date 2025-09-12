#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
    vector<int> par,comp_sz;
    DSU(int n){
        par.resize(n);
        comp_sz.resize(n);

        for(int i=0;i<n;i++){
            par[i]=i;
            comp_sz[i]=1;
        }
    }

    int get_par(int v){
        if(v==par[v])return v;
        return get_par(par[v]);
    }

    int doDsu(int x,int y){
        int px=get_par(x);
        int py=get_par(y);
        if(px==py){
            return 0;
        }

        if(comp_sz[px] > comp_sz[py]){
            swap(px,py);
        }

        par[px]=py;
        comp_sz[px]+=comp_sz[py];
        comp_sz[px]=0;

        return 1;
    }
};
class Solution {
public:
    bool check(int n, vector<vector<int> >&edges,vector<vector<int> >&poss,int mid,int k){
        DSU dsu = DSU(n);
        int ops=0;
        for(auto e:edges){
            if(e[3]==1){
                if(e[2]<mid){
                    return 0;
                }
                if(dsu.doDsu(e[0],e[1])==0){
                    return 0;
                }

                ops++;
            }
        }

        for(auto p:poss){
            if(dsu.get_par(p[1])==dsu.get_par(p[2])){
                continue;
            }

            if(p[0]<mid && k==0){
                continue;
            }

            if(p[0]*2<mid){
                continue;
            }

            dsu.doDsu(p[1],p[2]);
            ops++;
            if(p[0]<mid){
                k--;
            }
        }

        return ops==n-1;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        

        int ret=-1;
        vector<vector<int> > poss;
        
        for(auto e:edges){
            if(e[3]==0){
                poss.push_back({e[2],e[0],e[1]});
            }
        }

        sort(poss.begin(),poss.end());
        reverse(poss.begin(),poss.end());

        int lo=0,hi=2e5;

        while(hi>=lo){
            int mid=(hi+lo)/2;
            if(check(n,edges,poss,mid,k)){
                ret=max(ret,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }

        return ret;
    }
};