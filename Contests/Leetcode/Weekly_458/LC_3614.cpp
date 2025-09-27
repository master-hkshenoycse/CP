#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    char processStr(string s, long long k) {
        ll l=0;

        for(auto ch:s){
            if(ch>='a' && ch<='z'){
                l++;
            }else if(ch=='*'){
                if(l>0){
                    l--;
                }
            }else if(ch=='#'){
                l*=2;
            }
            
        }

        
        char ret='.';
        if(k>=l){
            return ret;
        }
        for(int i=s.size()-1;i>=0;i--){
            char c=s[i];
            if(c=='*'){
                l++;
            }else if(c=='#'){
                l/=2;
                if(k>=l){
                    k-=l;
                }
            }else if(c=='%'){
                k=l-1-k;
            }else{
                l--;
                if(l==k){
                    return c;
                }
            }
        }

        return '.';

        

    }
};