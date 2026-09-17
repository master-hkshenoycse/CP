#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(string &s, char x, char y){
        int cnt_x=0;
        for(auto ch:s){
            if(ch==y){
                if(cnt_x>0)
                    return 0;
            }
            if(ch==x)
                cnt_x++;
        }
        return 1;
    }
    string rearrangeString(string s, char x, char y) {
        sort(s.begin(),s.end());
        if(check(s,x,y))
            return s;
        reverse(s.begin(),s.end());
        return s;
    }
};