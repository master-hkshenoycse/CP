/*https://leetcode.com/discuss/interview-question/3933607/BNY-OA-2023-oror-Sum-of-Distances-oror-HARD*/
/*https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-143/problems*/

/*

For maximum
Take some node as root, calculate all subtrees sizes (call them array sz; nodes is all nodes numbers), then answer is 2 * sum(min(sz[v], n - sz[v]) for v in nodes).

Idea
For every edge let's imagine how many times it was passed. From one side of this edge sz[v] nodes, from other n - sz[v] (v is one of endpoints). Thus max number of times it can be passed is 2 * min(sz[v], n - sz[v]).

UPD: thanks to @srivatsasrinivas1729, he proved max part below.

For minimum
This code works:

bool dfs(const vector<vector<int>>& g, int& ans, int v, int p = -1) {
    int leafs = 0;
    for (auto to : g[v]) {
        if (to == p) continue;
        leafs += dfs(g, ans, to, v);
    }
    ans += leafs;
    return g[v].size() == 1 || leafs == 0;
}

int FindMinimum(const vector<vector<int>>& g) {
    if (g.size() == 2) return 2;
    int ans = 0, notLeaf = 0;
    for (; g[notLeaf].size() == 1; ++notLeaf);
    ans += dfs(g, ans, notLeaf);
    return 2 * ans;
}
Idea
For every node we can move no further then distance 2.
Proof: take some node as root, take any node with all children leafs. This sunny structure has no distance more than 2, can be easily permutated and cut from graph. Repeat until graph is empty.
Code above is actually this idea inside DFS.

UPD: for minimum answer is 2 * (n - max_matching), where max_matching is the size of maximum matching in this tree - can be found with DP[v][flag] (but still no proof).

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
  public:
    void dfs(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &subtree,ll n,ll &max_ans){
        
        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            dfs(to,v,adj,subtree,n,max_ans);
            subtree[v]+=subtree[to];
        }
        
        subtree[v]++;
        max_ans=max_ans+2ll*min(subtree[v],n-subtree[v]);
    }
    
    void max_matching(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &used,ll &min_ans){
        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            max_matching(to,v,adj,used,min_ans);
        }
        
        if(used[v]==0){
            min_ans++;
            used[v]=1;
            if(p>0){
                used[p]=1;
            }
        }
    }
    vector<long long> optShuffling(long long n, vector<vector<long long>> &edges) {
        // code here
        
        vector<vector<ll> > adj(n+1);
        vector<ll> subtree(n+1,0),used(n+1,0);
        
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        ll max_ans=0,min_ans=0;
        
        dfs(1,-1,adj,subtree,n,max_ans);
        max_matching(1,-1,adj,used,min_ans);
    
        min_ans=2*min_ans;
        
        
        return {min_ans,max_ans};
        
    }
};