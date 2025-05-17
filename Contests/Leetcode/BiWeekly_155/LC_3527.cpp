#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string findCommonResponse(vector<vector<string>>& responses) {
            map<string,int> help;
    
            for(auto r:responses){
                set<string> tmp;
                for(auto s:r){
                    if(tmp.find(s) == tmp.end()){
                        help[s]++;
                    }
                    tmp.insert(s);
                }
            }
    
            int cnt=0;
            string ret;
    
            for(auto it:help){
                if(it.second > cnt){
                    cnt=it.second;
                    ret=it.first;
                }
            }
    
            return ret;
        }
    };