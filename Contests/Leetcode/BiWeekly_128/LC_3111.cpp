#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(),points.end());
        int ans=0;

        int prev=-1e9-1;

        for(auto p:points){
            if(p[0]-prev > w){
                ans++;
                prev=p[0];
            }
        }   

        return ans;
    }
};