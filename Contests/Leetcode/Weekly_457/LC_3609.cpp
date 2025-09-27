#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
       int steps=0;
       while(1){
        if(sx==tx && sy==ty){
            return steps;
        }

        if(tx<sx || ty<sy){
            return -1;
        }

        if(tx>ty){
            if(tx%2==0 && tx>=2*ty){
                tx/=2;
            }else if(tx<=2*ty){
                tx-=ty;
            }else{
                return -1;
            }
        }else if(ty>tx){
            if(ty%2==0 && ty>=2*tx){
                ty/=2;
            }else if(ty<=2*tx){
                ty-=tx;
            }else{
                return -1;
            }
        }else{
            if(tx-ty>=sx){
                tx-=ty;
            }else if (ty-tx>=sy){
                ty-=tx;
            }else{
                return -1;
            }
        }
        steps++;
       }

       return -1;

    }
};