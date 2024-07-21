#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string losingPlayer(int x, int y) {
        int ch=0;
        while(x>=1 and y>=4){
            x-=1;
            y-=4;
            ch=1-ch;
        }
        
        if(ch==0){
            return "Bob";
        }
        
        return "Alice";
    }
};