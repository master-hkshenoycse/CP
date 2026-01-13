#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ret=INT_MAX;
        for(auto t: tasks){
            ret=min(ret,t[0]+t[1]);
        }
        return ret;
    }
};