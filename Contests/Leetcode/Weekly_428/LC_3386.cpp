#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int sol=0,ans=0,n=events.size();
        for(int i=0;i<n;i++){
            int push_time=events[i][1];
            if(i>0){
                push_time-=events[i-1][1];
            }

            if(ans<push_time){
                ans=push_time;
                sol=events[i][0];
            }else if(ans==push_time){
                sol=min(sol,events[i][0]);
            }
        }
        return sol;

    }
};