#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(string s) {
        int res=0,bal=0;
        for(auto ch:s){
            if(ch=='['){
                bal++;
            }else{
                bal--;
            }

            if(bal<0){
                res=max(res,abs(bal));
            }
        }

        return (res+1)/2;


    }
};