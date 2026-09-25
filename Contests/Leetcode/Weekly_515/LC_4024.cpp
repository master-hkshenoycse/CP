#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n=drones.size(),ret_dist=INT_MAX,ret_index=-1;

        for(int i=0;i<n;i++){
            int d=abs(target[0]-drones[i][0])+abs(target[1]-drones[i][1]);
            if(d <= drones[i][2]){
                if(ret_dist > d){
                    ret_dist=d;
                    ret_index=i;
                }
            }
        }

        return ret_index;
    }
};