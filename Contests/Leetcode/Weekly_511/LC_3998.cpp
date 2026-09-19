#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n=s.size(),c1=0,c0=0;

        for(auto ch:s)
            c1+=(ch=='1'),c0+=(ch=='0');
        
        vector<bool> ret;

        for(auto t:strs){

            int q_=0,c1_t=0,c0_t=0;
            for(auto ch:t)
                q_+=(ch=='?'),c1_t+=(ch=='1'),c0_t+=(ch=='0');
            
            int f=1;
            if(c1_t > c1 || c0_t> c0)
                f=0;
            
            if(f){
                int req_1=c1-c1_t;
                int req_0=c0-c0_t;
                int bal=0;
                for(int i=n-1;i>=0;i--){
                    if(t[i]=='?'){
                        if(req_1>0){
                            bal++;
                            req_1--;
                        }
                    }else{
                        bal+=(t[i]=='1');
                    }

                    bal-=(s[i]=='1');
                    if(bal<0)
                        f=0;
                }
            }


            ret.push_back(f);
        }

        return ret;
        
    }
};