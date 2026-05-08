#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistinct(string s) {
        int n=s.size();
        set<char> char_uniq;
        for(auto ch:s){
            char_uniq.insert(ch);
        }
        return char_uniq.size();
    }
};