#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_par(int v,vector<int> &par){
        if(par[v]==v){
            return v;
        }
        return get_par(par[v],par);
    }

    void do_dsu(int x,int y,vector<int> &par,vector<int> &sz){
        int px=get_par(x,par);
        int py=get_par(y,par);

        if(px==py){
            return;
        }

        if(sz[px]>sz[py]){
            swap(px,py);
        }

        par[px]=py;
        sz[py]+=sz[px];
        sz[px]=0;

    }
    int countComponents(vector<int>& nums, int threshold) {
        int ans=0;
        vector<int> par(threshold+1),sz(threshold+1,1);
        for(int i=1;i<=threshold;i++){
            par[i]=i;
        }
        map<int,int> help;
        for(auto e:nums){
            help[e]=1;
        }
        for(int i=1;i<=threshold;i++){
            if(help.find(i) == help.end()){
                continue;
            }
            for(int j=2*i;j<=threshold;j+=i){
                //cout<<i<<" "<<j<<endl;
                do_dsu(i,j,par,sz);
            }
        }

        set<int> comps;
        for(auto e:nums){
            if(e>threshold){
                comps.insert(e);
            }else{
                cout<<e<<" "<<get_par(e,par)<<endl;
                comps.insert(get_par(e,par));
            }
        }

        return comps.size();
    }
};