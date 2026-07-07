#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long sumAndMultiply(int n) {
        string num=to_string(n);
        ll ret=0,sod=0;
        for(auto ch:num){
            if(ch!='0')ret=ret*10+(ch-'0');
            sod+=(ch-'0');
        }
        return ret*sod;
    }
};