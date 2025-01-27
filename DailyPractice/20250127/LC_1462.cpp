#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> in_deg(numCourses,0);
        vector<vector<int> > adj(numCourses);

        for(auto p:prerequisites){
            in_deg[p[1]]++;
            adj[p[0]].push_back(p[1]);
        }

        vector< set<int> >pre_req(numCourses);
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in_deg[i]==0){
                q.push(i);
            }
        }

        while(q.size()>0){

            int v=q.front();
            q.pop();

            for(auto to:adj[v]){
                in_deg[to]--;
                pre_req[to].insert(v);

                for(auto e:pre_req[v]){
                    pre_req[to].insert(e);
                }
                if(in_deg[to]==0){
                    q.push(to);
                }
            }
        }

        vector<bool> sol;
        
        for(auto q:queries){
            int u=q[0];
            int v=q[1];
            if(pre_req[v].find(u)==pre_req[v].end()){
                sol.push_back(false);
            }else{
                sol.push_back(true);
            }
        }

        return sol;




    }
};