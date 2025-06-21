#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int get_value(string &s){
            int ret=0;
            for(auto ch:s){
                ret=ret*10+(ch-'0');
            }
            return ret;
        }
        
        bool is_valid(string &s){
            return s[0] != '0';
        }
        int maxDiff(int num) {
            int max_val = num;
            int min_val = num;
            string s = to_string(num);
    
            for(int x=0;x<=9;x++){
                for(int y=0;y<=9;y++){
                    string tmp=s;
    
                    for(auto &ch:tmp){
                        if(ch-'0'==x){
                            ch=char('0'+y);
                        }
                    }
    
                    if(is_valid(tmp)){
                        int val = get_value(tmp);
                        if(val > 0){
                            max_val=max(max_val,val);
                            min_val=min(min_val,val);
                        }
                    }
                }
            }
    
            return max_val-min_val;
        }
    };