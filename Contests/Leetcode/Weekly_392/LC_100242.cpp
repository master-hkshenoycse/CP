#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(string s, int k) {
        string sol;
        
        for(auto ch:s){
            for(int j=0;j<26;j++){
                
                int d=min(abs(j-(ch-'a')),26-abs(j-(ch-'a')));
                
                if(d<=k){
                    sol+=char('a'+j);
                    k-=d;
                    break;
                }
                
            }
        }
        
        return sol;
    }
};