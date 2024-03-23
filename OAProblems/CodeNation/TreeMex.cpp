/*https://leetcode.com/discuss/interview-question/1371073/Code-nation-or-OA-or-Find-Max-in-Tree-or-2021*/
#include<bits/stdc++.h>
using namespace std;

void solve(int n,vector<vector<int> > edges,vector<int>  c){
    vector<vector<int> > adj(n);
    for(auto e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> sol(n);
    set<int> 
}
int main(){


}