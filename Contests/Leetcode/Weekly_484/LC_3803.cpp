#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int residuePrefixes(string s) {
        int n=s.size(), ret=0;
        set<char> cnt;
        for(int i=0;i<n;i++){
            cnt.insert(s[i]);
            if((i+1)%3 == cnt.size())
                ret++;
        }
        return ret;
    }
};