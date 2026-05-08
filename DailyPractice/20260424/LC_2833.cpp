#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int no_=0,curr=0;
        
        for(auto ch:moves){
            if(ch=='L')curr--;
            else if(ch=='R')curr++;
            else{
                no_++;
            }
        }
        
        curr=abs(curr);
        curr+=no_;
        return curr;
    }
};