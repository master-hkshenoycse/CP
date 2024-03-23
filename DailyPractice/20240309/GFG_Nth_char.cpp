#include<bits/stdc++.h>
using namespace std;

char nthCharacter(string s, int r, int n) {
        //code here
        string curr=s;
        while(r--){
            string tmp;
            
            for(auto ch:curr){
                if(ch=='0'){
                    tmp+="01";
                }else{
                    tmp+="10";
                }
                if(tmp.size()>=n+1){
                    break;
                }
            }
            
            curr=tmp;
        }
        
        return curr[n];
    }