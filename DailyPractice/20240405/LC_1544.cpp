#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string sol;

        for(auto ch:s){
            if(sol.size()>0 and (ch-'A'==sol.back()-'a' or ch-'a'==sol.back()-'A')){
                sol.pop_back();
            }else{
                sol+=ch;
            }
        }

        return sol;
    }
};
