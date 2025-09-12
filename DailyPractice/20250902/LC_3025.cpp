#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                int cnt=0;
                int x_min=min(points[i][0],points[j][0]);
                int x_max=max(points[i][0],points[j][0]);
                int y_min=min(points[i][1],points[j][1]);
                int y_max=max(points[i][1],points[j][1]);
                
                for(int k=0;k<n;k++){
                    if(points[k][0]>=x_min and points[k][0]<=x_max and points[k][1]>=y_min and points[k][1]<=y_max){
                        cnt++;
                    }
                }
                
                if(cnt==2 and points[i][0]==x_min and points[i][1]==y_max and points[j][0]==x_max and points[j][1]==y_min){
                    ans++;
                }
            }
        }
        return ans;
    }
};