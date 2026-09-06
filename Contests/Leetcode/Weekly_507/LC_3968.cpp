#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(string moves) {
        int x=0,y=0,cnt_=0;
        for(auto ch:moves){
            if(ch=='U')
                y++;
            else if(ch=='D')
                y--;
            else if(ch=='L')
                x--;
            else if(ch=='R')
                x++;
            else
                cnt_++;
        }
        return abs(x)+abs(y)+cnt_;
    }
};