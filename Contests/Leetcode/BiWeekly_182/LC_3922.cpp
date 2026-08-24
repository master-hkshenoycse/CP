#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlips(string s) {
        int n=s.size(),cnt_0=0,cnt_1=0;

        for(auto ch:s){
            cnt_0=cnt_0+(ch=='0');
            cnt_1=cnt_1+(ch=='1');
        }
        
        if(cnt_0+cnt_1<=2)
            return 0;
        
        int len_max=cnt_1;
        len_max=max(len_max,cnt_0+(cnt_1>0));
        len_max=max(len_max,cnt_0+(s[0]=='1') +(s.back()=='1')); 
        return n-len_max;
    }
};