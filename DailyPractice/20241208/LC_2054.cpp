#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());

        vector<int> start_times(n),profits_cum(n);
        for(int i=0;i<n;i++){
            start_times[i]=events[i][0];
            profits_cum[i]=events[i][2];
        }

        for(int i=n-2;i>=0;i--){
            profits_cum[i]=max(profits_cum[i],profits_cum[i+1]);
        }
        int ans=0;

        for(int i=0;i<n;i++){
            int ret=events[i][2];
            int ind=upper_bound(start_times.begin(),start_times.end(),events[i][1])-start_times.begin();
            if(ind < n){
                ret+=profits_cum[ind];
            }
            ans=max(ans,ret);
        }
        return ans;
    }
};