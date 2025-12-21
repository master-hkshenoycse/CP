#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector< pair<int,int> >  >adj(n);
        for(auto m:meetings){
            adj[m[0]].push_back({m[2],m[1]});
            adj[m[1]].push_back({m[2],m[0]});
        }

        vector<int> know(n,INT_MAX);
        vector<int> sol;
        
        priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;//min heap
        pq.push({0,0});
        pq.push({0,firstPerson});

        while(pq.size()>0){
            int timing=pq.top().first;
            int v=pq.top().second;
            pq.pop();

            if(v==-1 or know[v]!=INT_MAX){
                continue;
            }

            sol.push_back(v);
            know[v]=timing;

            for(auto nx:adj[v]){    
                int m_time=nx.first;
                int person=nx.second;

                if(know[person]!=INT_MAX or m_time<timing){
                    //ignore if person already knows or too early to meet;
                    continue;
                }
                pq.push({m_time,person});
            }
        }

        return sol;            
    }
};