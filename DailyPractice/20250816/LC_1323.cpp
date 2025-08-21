#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int to_num(string &s){
        int y=0;
        for(auto ch:s){
            y=y*10+(ch-'0');
        }
        return y;
    }
    int maximum69Number (int num) {
        string u=to_string(num);
        int sz=u.size();
        
        for(int i=0;i<sz;i++){
            if(u[i]=='6'){
                u[i]='9';
                return to_num(u);
            }
            
        }
        
        return to_num(u);
    }
};