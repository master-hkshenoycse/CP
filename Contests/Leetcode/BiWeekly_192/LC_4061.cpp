#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if(target[0]==source[0] && source[1]==target[1])
            return 0;
        if(target[0]==source[0])
            return 1;
        if(target[1]==source[1])
            return 1;
        if(source[0]+source[1] == target[0]+target[1])
            return 1;
        if(source[0]-source[1] == target[0]-target[1])
            return 1;
        return 2;
    }
};