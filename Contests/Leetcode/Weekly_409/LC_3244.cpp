#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> intermediate_points;
        for(int i=1;i<n-1;i++){
            intermediate_points.insert(i);
        }

        vector<int> sol;

        for(auto q:queries){
            int st=q[0];
            int en=q[1];

            while(1){
                auto it=intermediate_points.upper_bound(st);
                if(it==intermediate_points.end() or *it >=en){
                    break;
                }
                st=*it;
                intermediate_points.erase(it);
            }

            sol.push_back(intermediate_points.size()+1);
        }
        return sol;
    }
};