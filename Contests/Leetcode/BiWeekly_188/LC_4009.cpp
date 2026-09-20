#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<array<int,5>, pair<int,int> > memo;
    int n;
    vector<int> demand;

    pair<int,int> dfs(int i,int f0,int f1,int w0,int w1){
        if(memo.count({i,f0,f1,w0,w1})) return memo[{i,f0,f1,w0,w1}];
        pair<int,int> res={-i,0};
        if(i==n) return res;

        int d=demand[i];
        if(f0>=d){
            pair<int,int> nxt=dfs(i+1,f0-d,f1,d,max(0,w1-w0));
            res=min(res,{nxt.first, max(nxt.second,w0)});
        }

        if(f1>=d){
            pair<int,int> nxt=dfs(i+1,f0,f1-d, max(0,w0-w1),d);
            res = min(res, {nxt.first, max(nxt.second, w1)});
        }

        return memo[{i, f0, f1, w0, w1}] = res;
    }
    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
        this->demand=demand;
        this->n=demand.size();
        auto res=dfs(0,fuel[0],fuel[1],0,0);
        return res.first ? res.second :-1;
    }
};