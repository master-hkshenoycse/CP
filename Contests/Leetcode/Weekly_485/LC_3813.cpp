#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int vowelConsonantScore(string s) {
        int vow=0, cons=0;
        for(auto ch:s){
            if(ch<'a' || ch>'z')
                continue;
        
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                vow++;
            else 
                cons++;
        }

        int score=0;
        if(cons>0)
            score=vow/cons;
        return score;
    }
};