#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size(),ans=0,bal=0;
        for(auto ch:s){
            if(ch=='('){
                bal++;
            }else{
                if(bal>0){
                    bal--;
                }else{
                    ans++;
                }
            }

        }

        return ans+bal;
    }
};