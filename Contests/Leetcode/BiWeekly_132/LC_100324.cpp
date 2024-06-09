#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string clearDigits(string s) {
        string sol;
        
        for(auto ch:s){
            if(ch>='0' and ch<='9'){
                sol.pop_back();
            }else{
                sol+=ch;
            }
        }
        
        return sol;
    }
};