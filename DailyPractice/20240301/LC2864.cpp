#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        int cnt_one=0,cnt_zero=0;
        for(int i=0;i<n;i++){
            cnt_one+=(s[i]=='1');
            cnt_zero+=(s[i]=='0');
        }
        
        string sol;
        for(int i=1;i<=cnt_one-1;i++){
            sol+='1';
        }
        
        for(int i=1;i<=cnt_zero;i++){
            sol+='0';
        }
        
        sol+='1';
        
        return sol;
    }
};