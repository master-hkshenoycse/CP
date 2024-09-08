#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string get_binary(int num){
        string ret;
        while(num>0){
            ret+=char('0'+(num%2));
            num/=2;
        }
        
        reverse(ret.begin(),ret.end());
        return ret;
    }
    string convertDateToBinary(string date) {
        string sol;
        int value=0;
        for(auto ch:date){
            if(ch=='-'){
                sol+=get_binary(value);
                value=0;
                sol+='-';
            }else{
                value=value*10+(ch-'0');
            }
        }
        
        sol+=get_binary(value);
        return sol;
    }
};