#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canAliceWin(int n) {
        int ch=0,poss=10;
        while(poss>0 and n>=poss){
            n-=poss;
            ch=1-ch;
            poss--;
        }

        return ch;

    }
};