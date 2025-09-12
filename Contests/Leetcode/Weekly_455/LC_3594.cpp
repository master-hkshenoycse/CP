#include<bits/stdc++.h>
using namespace std;
using State = tuple<double, int, int, int> ;
class Solution {
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        if(n>1 && k==1) return -1;

        priority_queue<State, vector<State>, greater<State> > pq;
        map<tuple<int, int, int>,double> dist;
        int lim = (1<<n)-1;

        vector<int> max_time(1<<n,0);
        for(int i=1;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    max_time[i]=max(max_time[i],time[j]);
                }
            }
        }

        pq.push({0.0,0,0,0});
        dist[{0,0,0}]=0.0;

        while(pq.size()>0){
            auto [d,s,x,b] = pq.top();
            pq.pop();

            //cout<<d<<" "<<s<<" "<<x<<" "<<b<<endl;
            if(x==lim){
                return d;
            }

            if(dist[{s,x,b}]<d){
                continue;
            }

            if(b){//Returning phase
                for(int i=0;i<n;i++){
                    if(x & (1<<i)){
                        int nx = ( x ^ (1<<i));
                        double rt=time[i]*mul[s];
                        double nd=d+rt;
                        int ns = (s+ (int)floor(rt))%m;
                        auto key = make_tuple(ns,nx,0);
                        if(dist.count(key)==0 || nd<dist[key]){
                            dist[key] = nd;
                            pq.push({nd,ns,nx,0});
                        }
                    }
                }
            }else{//Delivery phase
                for(int i=1;i<(1<<n);i++){

                    if(__builtin_popcount(i)>k){
                        continue;
                    }

                    if(i & x){
                        continue;
                    }

                    int nx = (x|i);
                    double dd = max_time[i]*mul[s];
                    double nd = d + dd;
                    int ns = (s+(int)floor(dd))%m;

                    auto key = make_tuple(ns,nx,1);

                    if(dist.count(key)==0 || nd<dist[key]){
                        dist[key]=nd;
                        pq.push({nd,ns,nx,1});
                    }
                }
            }
        }
        return -1;
    }
};