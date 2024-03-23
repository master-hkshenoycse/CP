#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) { 
        int n=points.size();

        for(int i=0;i<n;i++){
            swap(points[i][0],points[i][1]);
        }
        sort(points.begin(),points.end());

        int prev=points[0][0],ans=1;


        for(int i=1;i<n;i++){
            if(prev<points[i][1]){
                ans++;
                prev=points[i][0];
            }
        }
        return ans;
    }
};