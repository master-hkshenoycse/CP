#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findClosest(int x, int y, int z) {
            int tx = abs(x-z);
            int ty = abs(y-z);
    
            if(tx < ty) return 1;
            if(tx > ty) return 2;
            return 0;
        }
    };