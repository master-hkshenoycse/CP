#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level=0;
        for(auto l:logs){
            if(l=="./"){
                continue;
            }else if(l=="../"){
                if(level>0){
                    level--;
                }
            }else{
                level++;
            }
        }

        return level;
    }
};