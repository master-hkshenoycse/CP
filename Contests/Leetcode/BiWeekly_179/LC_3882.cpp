#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<unordered_set<int> > prev(m),curr(m);
        prev[0].insert(0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                curr[j].clear();
                int val=grid[i][j];

                for(auto poss:prev[j])
                    curr[j].insert(val ^ poss);
                
                if(j-1>=0){
                    for(auto poss:curr[j-1])
                        curr[j].insert(val ^ poss);
                }
            }
            prev=curr;
        }

        int ans=INT_MAX;
        for(auto v:curr[m-1])
            ans=min(ans,v);

        return ans;
    }
};