#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int get_val(string s){
            int v=0;
            for(auto ch:s){
                v=v*10+(ch-'0');
            }
            return v;
        }
        int minMaxDifference(int num) {
            int ma=0,mi=1e9;
            
            string curr=to_string(num);
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    
                    string tmp=curr;
                    
                    for(int k=0;k<curr.size();k++){
                        if(tmp[k]-'0'==i){
                            tmp[k]=char('0'+j);
                        }
                    }
                    
                    ma=max(ma,get_val(tmp));
                    mi=min(mi,get_val(tmp));
                }
            }
                
                
                
            return ma-mi;
        }
    };