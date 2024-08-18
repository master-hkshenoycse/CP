#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    bool check_palin(string &s){
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i] != s[n-i-1]){
                return 0;
            }
        }
        
        return 1;
    }
    string get_num(int len,int k){
        
        int req=0;
        for(int i=k;i<1000000;i+=k){
            string tmp=to_string(i);
            if(tmp.size()==len and check_palin(tmp)){
                req=max(req,i);
            }
            
            if(tmp.size()>len){
                break;
            }
        }
        
        string ret;
        ret=to_string(req);
        
        return ret;   
    }
    
    int get_rem(string &s,int k){
        int rem=0;
        for(auto ch:s){
            rem=(rem*10+ (ch-'0'))%k;
        }
        return rem;
    }
    string largestPalindrome(int n, int k) {
        string sol;
        
        for(int i=1;i<=n;i++){
                sol+='9';
        }
            
        if(k==1 or k==3 or k==9){
            return sol;
        }
        
        if(k==5){
            sol[0]='5';
            sol[n-1]='5';
            return sol;
        }
        
        
        if(k==2){
            sol[0]='8';
            sol[n-1]='8';
            
            return sol;
        }
        
        if(k==4){
            if(n<=4){
                return get_num(n,k);
            }
            
            sol[0]='8';
            sol[1]='8';
            sol[n-1]='8';
            sol[n-2]='8';
        }
        
        
        if(k==6){
            if(n<=5){
                return get_num(n,k);
            }
            
            sol[0]='8';
            sol[n-1]='8';
            
            
            if(n%2){
                for(int i=9;i>=0;i--){
                    sol[n/2]=char('0'+i);
                    if(get_rem(sol,k)==0){
                        return sol;
                    }
                }
                
            }else{
                for(int i=9;i>=0;i--){
                    sol[n/2]=char('0'+i);
                    sol[n/2-1]=char('0'+i);
                    if(get_rem(sol,k)==0){
                        return sol;
                    }
                }
            
            }
        }
        
        if(k==7){
            
            if(n%2){
                for(int i=9;i>=0;i--){
                    sol[n/2]=char('0'+i);
                    if(get_rem(sol,k)==0){
                        return sol;
                    }
                }
                
            }else{
                for(int i=9;i>=0;i--){
                    sol[n/2]=char('0'+i);
                    sol[n/2-1]=char('0'+i);
                    if(get_rem(sol,k)==0){
                        return sol;
                    }
                }
            
            }
            
            
        }
        
        if(k==8){
            if(n<=6){
                return get_num(n,k);
            }
            
            sol[0]='8';
            sol[1]='8';
            sol[2]='8';
            sol[n-1]='8';
            sol[n-2]='8';
            sol[n-3]='8';
            
            return sol;
            
        }
        
        
        
        return sol;
    }
};