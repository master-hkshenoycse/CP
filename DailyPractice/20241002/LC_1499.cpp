#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        multiset<int> xy_vals;
        int j=0,n=points.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            while(j<i and points[i][0]-points[j][0]>k){
                xy_vals.erase(xy_vals.find(points[j][1]-points[j][0]));
                j++;
            }

            if(xy_vals.size()>0){
                ans=max(ans,points[i][0]+points[i][1]+*(--xy_vals.end()));
            }
            xy_vals.insert(points[i][1]-points[i][0]);
        }

        xy_vals.clear();
        j=n-1;

        for(int i=n-1;i>=0;i--){
            while(j>i and points[j][0]-points[i][0]>k){
                xy_vals.erase(xy_vals.find(points[j][1]+points[j][0]));
                j--;
            }

            if(xy_vals.size()>0){
                ans=max(ans,-points[i][0]+points[i][1]+*(--xy_vals.end()));
            }
            xy_vals.insert(points[i][1]+points[i][0]);
        }


        return ans;
    }
};