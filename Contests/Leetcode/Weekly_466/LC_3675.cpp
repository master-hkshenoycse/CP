#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        set<char> c;
        for(auto ch:s){
            if(ch != 'a'){
                c.insert(ch);
            }
        }

        if(c.size()>0){
            return 26-(*c.begin()-'a');
        }
        return 0;
    }
};