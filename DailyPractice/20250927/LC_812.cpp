#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double get_area(vector<int> &p1,vector<int> &p2,vector<int> &p3){
        double area = p1[0]*1.00*(p2[1]*1.00-p3[1]*1.00) + p2[0]*1.00*(p3[1]*1.00-p1[1]*1.00) + p3[0]*1.00*(p1[1]*1.00-p2[1]*1.00);
        return abs(area/2.00);
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans=0.0;
        int n=points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    ans=max(ans,get_area(points[i],points[j],points[k]));
                }
            }
        }
        return ans;
    }
};