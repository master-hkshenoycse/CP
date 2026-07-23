#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ret;

        for(auto w:words){
            int map=0;
            for(char ch:w)
                map=(map+weights[ch-'a'])%26;
            ret=ret+char('a'+25-map);        
        }

        return ret;
    }
};