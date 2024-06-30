#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        
        for(int i=100;i>=1;i--){
            int total_req=(i*i+i)/2ll;
            int ty1_req=((i+1)/2)*((i+1)/2);
            int ty2_req=total_req-ty1_req;

            if(ty1_req<=red and ty2_req<=blue){
                return i;
            }

            if(ty1_req<=blue and ty2_req<=red){
                return i;
            }
        }   

        return 0;
    }
};