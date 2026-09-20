#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countValidPrefixes(string s) {
        int ret=0,c1=0,c0=0;
        for(auto ch:s){
            if(ch=='1'){
                c1++;
            }else{
                c0++;
            }
            if(abs(c1-c0)<2){
                ret++;
            }
        }
        return ret;
    }
};