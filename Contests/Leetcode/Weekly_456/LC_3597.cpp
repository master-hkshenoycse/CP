#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> partitionString(string s) {
        set<string> seen;
        vector<string> sol;

        string seg;
        for(auto ch:s){
            seg+=ch;
            if(seen.find(seg) == seen.end()){
                sol.push_back(seg);
                seen.insert(seg);
                seg.clear();
            }
        }

        return sol;
    }
};