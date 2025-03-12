#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool hasSameDigits(string s) {
            int n=s.size();
            while(s.size()>2){
                string tmp;
                for(int i=0;i+1<s.size();i++){
                    int value=(s[i]-'0')+(s[i+1]-'0');
                    value%=10;
                    tmp+=char('0'+value);
                }
                s=tmp;
            }
            return (s[0]==s[1]);
        }
    };