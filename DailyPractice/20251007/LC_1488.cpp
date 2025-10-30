#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        vector<int> nx_t(n,n);
        map<int,int> help;
        vector<int> sol(n,-1);

        for(int i=n-1;i>=0;i--){
            if(rains[i] != 0){
                if(help.find(rains[i]) != help.end()){
                    nx_t[i]=help[rains[i]];
                }
                help[rains[i]]=i;
            }
        }

        priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > pq;
        for(int i=0;i<n;i++){

            if(pq.size()>0 && pq.top().first <= i){
                return {};
            }

            if(rains[i] != 0){
                pq.push({nx_t[i],rains[i]});
            }else{
                if(pq.size()>0){
                    sol[i]=pq.top().second;
                    pq.pop();
                }else{
                    sol[i]=1;
                }
            }   
        }


        return sol;
    }
};