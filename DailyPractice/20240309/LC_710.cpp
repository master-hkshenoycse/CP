#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    mt19937 gen;
    uniform_int_distribution<> dis;
    vector<int> prefix;

    //intialize the distribution and to ignore blacklist 

    Solution(int n, vector<int>& blacklist):dis() {
        sort(blacklist.begin(),blacklist.end());
        for(int i=0;i<blacklist.size();i++){
            prefix.push_back(blacklist[i]-i);
        }
        prefix.push_back(n-blacklist.size());

        dis = uniform_int_distribution<>(0, n - int(blacklist.size()) - 1);
    }
    
    int pick() {
        int idx=dis(gen);
        return idx+upper_bound(prefix.begin(),prefix.end(),idx)-prefix.begin();
    }
};

