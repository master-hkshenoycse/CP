#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rotatedDigits(int n) {
        int ret=0;
        map<int,int> ret_dig;
        ret_dig[0]=0;
        ret_dig[1]=1;
        ret_dig[8]=8;
        ret_dig[2]=5;
        ret_dig[5]=2;
        ret_dig[6]=9;
        ret_dig[9]=6;
        for(int i=1;i<=n;i++){
            int f=1;
            string curr=to_string(i);
            int new_num=0;
            for(auto ch:curr){
                if(ch=='3' || ch=='4' || ch=='7'){
                    f=0;
                    break;
                }
                new_num=new_num*10+ret_dig[ch-'0'];
            }
            if(new_num !=i && f==1)
                ret++;
        }
        return ret;
    }
};