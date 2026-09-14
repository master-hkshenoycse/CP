#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_rep(string &s){
        return ((s[0]-'0')*10+(s[1]-'0'))*3600 + ((s[3]-'0')*10+(s[4]-'0'))*60+((s[6]-'0')*10+(s[7]-'0'));
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        return get_rep(endTime)-get_rep(startTime);
    }
};