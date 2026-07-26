#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string maximumXor(string s, string t) {
        int cnt_ze=0,cnt_on=0;
        for(auto ch: t){
            if(ch=='0')cnt_ze++;
            else cnt_on++;
        }

        string ret;

        for(auto ch:s){
            if(ch=='0'){
                if(cnt_on>0){
                    ret+='1';
                    cnt_on--;
                }else{
                    ret+='0';
                    cnt_ze--;
                }
            }else{
                if(cnt_ze>0){
                    ret+='1';
                    cnt_ze--;
                }else{
                    ret+='0';
                    cnt_on--;
                }
            }
        }


        return ret;
    }
};