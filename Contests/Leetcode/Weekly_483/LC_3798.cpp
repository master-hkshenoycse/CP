#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestEven(string s) {
        while(s.size()>0 && s.back()=='1')
            s.pop_back();
        return s;
    }
};