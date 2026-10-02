#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        ll ret=0;
        priority_queue<int,vector<int>,greater<int> > pq;
        sort(intervals.begin(),intervals.end());
        for(auto it:intervals){
            while(pq.size()>0 && pq.top()<it[0]){
                pq.pop();
            }
            ret=ret+pq.size();
            pq.push(it[1]);
        }

        return ret;
    }
};