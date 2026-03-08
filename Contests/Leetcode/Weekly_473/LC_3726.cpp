#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long removeZeros(long long n) {
        string str_n=to_string(n);
        ll ret=0;
        for(auto ch:str_n){
            if(ch!='0')ret=ret*10+(ch-'0');
        }
        return ret;
    }
};