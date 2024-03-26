#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string get_add(string &a,string &b){
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
    
        
        string sol;
        int c=0,i=0,n=a.size(),m=b.size();
        
        while(i<n or i<m){
            int v1=0,v2=0;
            if(i<n){
                v1=a[i]-'0';
            }
            
            if(i<m){
                v2=b[i]-'0';
            }
            
            int v=(v1+v2+c)%10;
            c=(v1+v2+c)/10;
            
            sol+=char('0'+v);
            
            i++;
        
        }
        
        if(c>0){
            sol+=char('0'+c);
        }
        
    
        reverse(sol.begin(),sol.end());
        return sol;        
    }
    bool isAdditiveSequence(string s) {
        // Your code here
        int n=s.size();
        
        for(int i=0;i<n;i++){
            string a_=s.substr(0,i+1);
            string b_;
            for(int j=i+1;j+1<n;j++){
                
                b_+=s[j];
                int f=1;
                
                string a=a_,b=b_;
                int k=j+1;
                while(k<n){
                    string req=get_add(a,b);
                    int sz=req.size();
                    
                    if(k+sz-1>=n){
                       f=0;
                       break;
                    }
                    
                    if(s.substr(k,sz) != req){
                        f=0;
                        break;
                    }
                    
                    a=b;
                    b=req;
                    k+=sz;
                }
                
                if(f){
                    return 1;
                }
                
            }
        }
        
        return 0;
    }
};