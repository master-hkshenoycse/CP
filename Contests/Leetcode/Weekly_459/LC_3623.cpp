#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();

        map<int,int> cnt_y;
        for(auto p:points){
            cnt_y[p[1]]++;
        } 


        ll ret=0,sum_of_points=0;
        for(auto it:cnt_y){
            ll c=it.second;
            c=(c*c-c)/2ll;
            c%=mod;
            ret=ret+(c * sum_of_points)%mod;
            ret%=mod;
            sum_of_points=(sum_of_points+c)%mod;
        }
        
        return ret;
        
    }
};