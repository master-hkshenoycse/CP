#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        for(int x=-radius;x<=radius;x++){
            for(int y=-radius;y<=radius;y++){
                int nx=x_center+x;
                int ny=y_center+y;
                
                if(x*x+y*y<= radius*radius and nx>=x1 and nx<=x2 and ny>=y1 and ny<=y2){
                    return 1;
                }
            }
        }
        return 0;
    }
};