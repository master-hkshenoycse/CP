#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int p1=(source[0]+source[1])%2;
        int p2=(target[0]+target[1])%2;
        if(p1 != p2)
            return -1;
        
        int d1_s=(source[0]+source[1]);
        int d2_s=(source[0]-source[1]);
        int t1_s=(target[0]+target[1]);
        int t2_s=(target[0]-target[1]);

        if((d1_s == t1_s) || (d2_s == t2_s))
            return 1;
        
        return 2;
    }
};