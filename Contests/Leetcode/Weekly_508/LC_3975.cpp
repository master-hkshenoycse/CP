#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        vector<vector<int> > intervals;

        int l=-1,r=-1;

        for(auto it:occupiedIntervals){
            if(it[0]>r){
                if(l!=-1){
                    intervals.push_back({l,r});
                }
                l=it[0];
                r=it[1];
            }else{
                r=max(r,it[1]);
            }
        }

        if(l!=-1)
            intervals.push_back({l,r});
        
        vector<vector<int> > ret;

        for(auto it:intervals){
            int l=it[0],r=it[1];

            if(freeStart>r ||freeEnd<l){
                ret.push_back({l,r});
                continue;
            }

            if(freeStart<=l && freeEnd>=r){
                continue;
            }

            if(freeStart>l  && freeEnd>=r){
                ret.push_back({l,freeStart-1});
                continue;
            }

            if(freeStart<=l && freeEnd<r){
                ret.push_back({freeEnd+1,r});
                continue;
            }

            ret.push_back({l,freeStart-1});
            ret.push_back({freeEnd+1,r});

        }

        vector<vector<int> > final_ret;

        int i=0;
        int n=ret.size();
        while(i<n){
            int j=i+1;
            while(j<n && ret[j][0]-ret[j-1][1]==1)
                j++;
            final_ret.push_back({ret[i][0],ret[j-1][1]});
            i=j;
        }

        return final_ret;
    }
};