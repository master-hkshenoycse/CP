#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int> > ret;

        int n=series1.size(),m=series2.size();
        int i=0,j=0;

        while(i<n && j<m){
            int t1=series1[i][0];
            int t2=series2[j][0];
            int val=series1[i][1]+series2[j][1];

            if(t1<t2){
                ret.push_back({t1,val});
                i++;
            }else if(t1>t2){
                ret.push_back({t2,val});
                j++;
            }else{
                ret.push_back({t1,val});
                i++;
                j++;
            }
        }

        while(i<n)
            ret.push_back(series1[i++]);

        while(j<m)
            ret.push_back(series2[j++]);

        return ret;
    }
};