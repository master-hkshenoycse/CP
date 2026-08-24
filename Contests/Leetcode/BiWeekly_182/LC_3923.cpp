#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        
        int iter=0;
        while(iter<=15){
            set<vector<int> > next_points;
            for(auto p:points){
                next_points.insert(p);
                if(p[0]==target[0] && p[1]==target[1] && p[2]==target[2])
                    return iter;
            }

            int sz=points.size();
            

            for(int i=0;i<sz;i++){
                for(int j=i+1;j<sz;j++){
                    next_points.insert({(points[i][0]+points[j][0])/2,
                                        (points[i][1]+points[j][1])/2,
                                        (points[i][2]+points[j][2])/2});
                }
            }

            if(next_points.size()==points.size())
                break;

            points.clear();
            for(auto p:next_points)
                points.push_back(p);

            iter++;
        }

        return -1;
    }
};