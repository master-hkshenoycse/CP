#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string processStr(string s) {
        string ret;

        for(auto ch:s){
            if(ch>='a' && ch<='z'){
                ret+=ch;
            }else if(ch=='*'){
                if(ret.size()>0){
                    ret.pop_back();
                }
            }else if(ch=='#'){
                ret+=ret;
            }else{
                reverse(ret.begin(),ret.end());
            }
        }

        return ret;
    }
};