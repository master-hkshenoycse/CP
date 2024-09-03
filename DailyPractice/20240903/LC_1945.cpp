#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int get_sod(string &s){
        int ret=0;
        for(auto ch:s){
            ret=ret+(ch-'0');
        }
        return ret;
    }
    int getLucky(string s, int k) {
        
        string num;
        for(auto ch:s){
            num+=to_string(ch-'a'+1);
        }

        int ans=0;
        while(k--){
           ans=get_sod(num);
           num=to_string(ans); 
        }

        return ans;
    }
};