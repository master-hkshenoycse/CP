#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        
        bool chk(string &s,int ind,int rem){
            if(ind==s.size()){
                return rem==0;
            }
            
            
            int res=0,v=0,sz=s.size();
            for(int i=ind;i<sz;i++){
                v=v*10+(s[i]-'0');
                if(v<=rem){
                    res=(res | chk(s,i+1,rem-v));
                }
                
                if(res==1){
                    return 1;
                }
            }
            
            return 0;
            
        }
        int punishmentNumber(int n) {
            int ans=0;
            
            for(int i=1;i<=n;i++){
                string y=to_string(i*i);
                if(chk(y,0,i)){
                    ans=ans+(i*i);
                }
            }
            
            return ans;
        }
    };