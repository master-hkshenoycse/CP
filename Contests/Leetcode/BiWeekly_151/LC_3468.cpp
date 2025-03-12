#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
            int n=original.size();
            int lo=INT_MIN,hi=INT_MAX;
            lo=bounds[0][0];
            hi=bounds[0][1];
            for(int i=1;i<n;i++){
                int diff=original[i]-original[i-1];
                int lo_c=lo+diff;
                int hi_c=hi+diff;
                
                lo=max(lo_c,bounds[i][0]);
                hi=min(hi_c,bounds[i][1]);
            }
            
            int ret=0;
            if(hi>=lo){
                ret=hi-lo+1;
            }
            return ret;
        }
    };