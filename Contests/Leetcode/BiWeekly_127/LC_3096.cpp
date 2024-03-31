#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int total=0,cs=0;
        for(auto p:possible){
            if(p==0)total--;
            else total++;
        }

        for(int i=0;i<possible.size()-1;i++){
            if(possible[i]==0)cs--;
            else cs++;

            if(cs>total-cs){
                return i+1;
            }
        }
        return -1;
    }
};