#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        int x=sqrt(c);
        
        for(int i=0;i<=x;i++){
            int y=sqrt(c-i*i);
            if(y*y+i*i==c){
                return 1;
            }
        }
        return 0;
        
    }
};