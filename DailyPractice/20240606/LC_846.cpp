#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> help;

        for(auto e:hand){
            help[e]++;
        }
        
        for(auto it:help){
            int req=it.second;
            int curr=it.first;

            if(req==0){
                continue;
            }

            for(int j=curr;j<=curr+groupSize-1;j++){

                if(help.find(j)==help.end()){
                    return 0;
                }

                if(help[j]<req){
                    return 0;
                }

                help[j]-=req;
            }
        }

        return 1;

    }
};