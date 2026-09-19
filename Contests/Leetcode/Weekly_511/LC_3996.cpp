#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dx[8]={-2,-1,1,2,2,1,-1,-2};
    int dy[8]={1,2,2,1,-1,-2,-2,-1};
    bool canReach(vector<int>& start, vector<int>& target) {
        int p1=(start[0]+start[1])%2;
        int p2=(target[0]+target[1])%2;

        return p1==p2;
    }
};