#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(string &t,string &s){
        for(int i=0;i<5;i++){
            if(s[i]=='?'){
                continue;
            }
            if(s[i]!=t[i]){
                return 0;
            }
        }

        return 1;
    }
    string findLatestTime(string s) {
      string ans;
       for(int i=0;i<12;i++){
        for(int j=0;j<60;j++){
            string h;
            h+=char('0'+i/10);
            h+=char('0'+(i%10));

            string m;
            m+=char('0'+j/10);
            m+=char('0'+(j%10));

            string y=h+':'+m;
            
            if(check(y,s)){
                ans=y;
            }
        }
       }
       return ans; 
    }
};