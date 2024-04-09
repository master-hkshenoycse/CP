#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int maxDiff=0,minDiff=0;

        //* two options are there 
        for(auto ch:s){
            if(ch=='('){
                maxDiff++;
                minDiff++;
            }else if(ch==')'){
                maxDiff--;
                minDiff--;
            }else{
                maxDiff++;
                minDiff--;
            }

            minDiff=max(0,minDiff);
            if(maxDiff<0){
                return 0;
            }
        }

        return minDiff==0;
    }
};