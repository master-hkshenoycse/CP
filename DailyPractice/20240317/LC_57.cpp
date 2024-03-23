#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();

        vector<vector<int> > sol;

        int st=intervals[0][0],en=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>en){
                sol.push_back({st,en});
                st=intervals[i][0];
                en=intervals[i][1];
            }else{
                en=max(en,intervals[i][1]);
            }
        }
        sol.push_back({st,en});
        return sol;
    }
};