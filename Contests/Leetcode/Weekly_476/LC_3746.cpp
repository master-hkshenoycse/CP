#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n=s.size();
        int bal=0;
        for(auto ch:s){
            if(ch=='a')bal++;
            else bal--;
        }
        return abs(bal);
    }
};