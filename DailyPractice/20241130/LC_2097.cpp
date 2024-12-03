#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int node,unordered_map<int,vector<pair<int,int> > >&adj,vector<vector<int> >&pairs,vector<bool>& used, deque<vector<int>>& result){

        while(!adj[node].empty()){
            auto [next,idx]=adj[node].back();
            adj[node].pop_back();

            if(!used[idx]){
                used[idx]=true;
                dfs(next,adj,pairs,used,result);
                result.push_front(pairs[idx]);
            }

        }


    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<pair<int,int> > >adj;
        unordered_map<int,int> indegree,outdegree;
        vector<bool> used(pairs.size(),false);

        for(int i=0;i<pairs.size();i++){
            int start=pairs[i][0];
            int end=pairs[i][1];
            adj[start].push_back({end,i});
            outdegree[start]++;
            indegree[end]++;
        }

        int startNode=pairs[0][0];
        for(auto &pair:pairs){
            if(outdegree[pair[0]] > indegree[pair[0]]){
                startNode=pair[0];
                break;
            }
        }
        deque<vector<int> > result;
        dfs(startNode,adj,pairs,used,result);

        return vector<vector<int> > (result.begin(),result.end());
    }
};
