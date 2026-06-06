#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int n=towers.size();
        vector<int> ret={-1,-1};
        int q_max=-1;

        for(auto t:towers){
            if(abs(t[0]-center[0])+abs(t[1]-center[1])<=radius){
                if(t[2]>q_max){
                    q_max=t[2];
                    ret={t[0],t[1]};
                }else if(t[2]==q_max){
                    ret=min(ret,{t[0],t[1]});
                }
            }
        }

        return ret;

    }
};