#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans=0,n=intervals.size();
        for(int i=0;i<n;i++){
            int f=0;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(intervals[i][0]>=intervals[j][0] and intervals[i][1]<=intervals[j][1]){
                    f=1;
                    break;
                }
            }
            ans+=f;
        }
        
        return n-ans;
    }
};