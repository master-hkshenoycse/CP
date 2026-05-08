#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        for(auto ch:moves){
            if(ch=='U')y++;
            else if(ch=='D')y--;
            else if(ch=='L')x--;
            else if(ch=='R')x++;
        }
        return x==0 && y==0;
    }
};