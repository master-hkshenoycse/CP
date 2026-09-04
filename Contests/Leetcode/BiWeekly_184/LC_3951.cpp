#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());
        ll tot=0,r=-1,l=-1;

        for(auto it:intervals){
            if(r<it[0]){
                if(l!=-1)
                    tot+=(r-l+1);
                l=it[0];
                r=it[1];
            }else{
                r=max(r,it[1]*1ll);
            }
        }

        if(l!=-1)
           tot+=(r-l+1);

        return tot*((brightness+2)/3);
    }
};