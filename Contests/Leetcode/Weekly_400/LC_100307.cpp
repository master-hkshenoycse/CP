#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumChairs(string s) {
        int ans=0,bal=0;
        for(auto ch:s){
            if(ch=='E'){
                bal--;
                if(bal<0){
                    ans=max(ans,abs(bal));
                }
            }else{
                bal++;
            }
        }
        
        return ans;
    }
};