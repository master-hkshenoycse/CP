#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
    int n;
    vector<int> par,comp_sz;

    DSU(int n){
        this->n = n;
        par.resize(n+1),comp_sz.resize(n+1);
        for(int i=1;i<=n;i++){
            par[i]=i;
            comp_sz[i]=1;
        }
    }

    int get_par(int v){
        if(v==par[v])return v;
        return get_par(par[v]);
    }

    void doDSU(int x,int y){
        int px=get_par(x);
        int py=get_par(y);

        if(px==py){
            return;
        }

        if(comp_sz[px]>comp_sz[py]){
            swap(px,py);
        }

        par[px]=py;
        comp_sz[py]+=comp_sz[px];
        comp_sz[px]=0;
    }
};
class Solution {
public:

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries){
        
        DSU dsu = DSU(c);
        for(auto c:connections){
            dsu.doDSU(c[0],c[1]);
        }   

        vector<set<int> > online_(c+1);
        vector<int> is_online(c+1);
        for(int i=1;i<=c;i++){
            is_online[i]=1;
            online_[dsu.get_par(i)].insert(i);
        }

        vector<int> ret;

        for(auto q:queries){
            int p=dsu.get_par(q[1]);
            if(q[0]==1){
                if(is_online[q[1]]){
                    ret.push_back(q[1]);
                }else if(online_[p].size()>0){
                    ret.push_back(*online_[p].begin());
                }else{
                    ret.push_back(-1);
                }
            }else{
                online_[p].erase(q[1]);
                is_online[q[1]]=0;
            }   
        }

        return ret;


    }
};