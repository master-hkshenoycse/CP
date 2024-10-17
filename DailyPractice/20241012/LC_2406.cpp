#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        for(int i=0;i<n;i++){
            swap(intervals[i][0],intervals[i][1]);
        }

        sort(intervals.begin(),intervals.end());

        multiset<int> event_ends;
        multiset<int> :: iterator it;
        for(auto i:intervals){
            int start=i[1];
            int end=i[0];
            if(event_ends.size()==0){
                event_ends.insert(end);
            }else{
                it=event_ends.lower_bound(start);
                if(it!=event_ends.begin()){
                    it--;
                    event_ends.erase(it);
                }
                event_ends.insert(end);
            }
        }

        return event_ends.size();
    }
};