#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int v,int p,int index_rep,vector<vector<pair<int,int> > > &adj,vector<int> &nums,vector<int> &path,vector<int> &cum_wt_array,int path_len,map<int,vector<int> > &help,vector<int> &ret){
        
        path.push_back(nums[v]);
        cum_wt_array.push_back(path_len);
        

        if(help.find(nums[v]) != help.end() and help[nums[v]].size()>0){
            index_rep=max(index_rep,help[nums[v]].back());
        }
        
        int uniq_len=path_len;
        if(index_rep !=-1 ){
            uniq_len-=cum_wt_array[index_rep+1];
        }
        
        if(ret[0] < uniq_len){
            ret[0]=uniq_len;
            ret[1]=path.size()*1-index_rep-1;
        }else if(ret[0]==uniq_len){
            int sz=path.size();
            ret[1]=min(ret[1],sz-index_rep*1-1);
        }
        
        help[nums[v]].push_back(path.size()-1);
        
        
        for(auto to:adj[v]){
            if(to.first==p){
                continue;
            }
            dfs(to.first,v,index_rep,adj,nums,path,cum_wt_array,path_len+to.second,help,ret);
        }
        
        path.pop_back();
        cum_wt_array.pop_back();
        help[nums[v]].pop_back();
        
    }
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n=nums.size();
        vector<vector<pair<int,int> > > adj(n);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        vector<int> ret={INT_MIN,INT_MAX};
        
        vector<int> node_array,cum_wt_array;
        map<int,vector<int> >help;
        
        dfs(0,-1,-1,adj,nums,node_array,cum_wt_array,0,help,ret);
        
        return ret;
        
    }
};