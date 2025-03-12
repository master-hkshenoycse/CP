#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> lps_get(string s,string p){
            int sp=p.size();
            p+='$';
            p+=s;
            int n=p.size();
            vector<int> lps(n,0);
            int i=1,len=0;
           
    
            while(i<n){
                if(p[i]==p[len]){
                    len++;
                    lps[i]=len;
                    i++;
                }else{
                    if(len != 0){
                        len=lps[len-1];
                    }else{
                        i++;
                    }
                    
                }
            }
    
            vector<int> ret;
            for(int i=sp+1;i<lps.size();i++){
                ret.push_back(lps[i]);
            }
    
            return ret;
        }
        int shortestMatchingSubstring(string s, string p) {
            string x,y,z;
            int c=0;
            for(auto ch:p){
                if(ch=='*'){
                    c++;
                }else{
                     if(c==0){
                         x+=ch;
                     }else if(c==1){
                         y+=ch;
                     }else{
                         z+=ch;
                     }
                }
            }
    
            
    
            int sx=x.size(),sy=y.size(),sz=z.size();
            vector<int> lps_x=lps_get(s,x);
            vector<int> lps_y=lps_get(s,y);
            vector<int> lps_z=lps_get(s,z);
    
            
            int n=s.size();
    
          
    
            if(sx==0 && sy==0 && sz==0){
                return 0;
            }
    
            if(sx==0 && sy==0 && sz>0){
                for(int i=0;i<n;i++){
                    if(lps_z[i]==sz){
                        return sz;
                    }
                }
                return -1;
            }
    
            if(sx==0 && sy>0 && sz==0){
                for(int i=0;i<n;i++){
                    if(lps_y[i]==sy){
                        return sy;
                    }
                }
                return -1;
            }
    
            if(sx>0 && sy==0 && sz==0){
                for(int i=0;i<n;i++){
                    if(lps_x[i]==sx){
                        return sx;
                    }
                }
                return -1;
            }
    
            if(sx>0 && sy==0 && sz>0){
                int ret=n+1;
                set<int> nx_z;
                for(int i=n-1;i>=0;i--){
    
                    if(lps_x[i]==sx){
                        auto it=nx_z.upper_bound(i);
                        int st=i-sx+1;
                        if(it != nx_z.end()){
                            ret=min(ret,(*it)+sz-st);
                        }
                        
                    }
                    
                    if(lps_z[i]==sz){
                        nx_z.insert(i-sz+1);
                    }
                }
    
                if(ret==n+1){
                    ret=-1;
                }
    
                return ret;
            }
    
            if(sx>0 && sy>0 && sz==0){
                int ret=n+1;
                set<int> nx_y;
                for(int i=n-1;i>=0;i--){
    
                    if(lps_x[i]==sx){
                        auto it=nx_y.upper_bound(i);
                        int st=i-sx+1;
                        if(it != nx_y.end()){
                            ret=min(ret,(*it)+sy-st);
                        }
                        
                    }
                    
                    if(lps_y[i]==sy){
                        nx_y.insert(i-sy+1);
                    }
                }
    
                if(ret==n+1){
                    ret=-1;
                }
    
                return ret;
            }
    
            if(sx==0 && sy>0 && sz>0){
    
                int ret=n+1;
                set<int> nx_z;
                for(int i=n-1;i>=0;i--){
    
                    if(lps_y[i]==sy){
                        auto it=nx_z.upper_bound(i);
                        int st=i-sy+1;
                        if(it != nx_z.end()){
                            ret=min(ret,(*it)+sz-st);
                        }
                        
                    }
                    
                    if(lps_z[i]==sz){
                        nx_z.insert(i-sz+1);
                    }
                }
    
                if(ret==n+1){
                    ret=-1;
                }
    
                return ret;
                
            }
    
            int ret=n+1;
            vector<int> val_y(n,n+1);
            set<int> nx_y,nx_z;
    
            for(int i=n-1;i>=0;i--){
                if(lps_x[i]==sx){
                    auto it=nx_y.upper_bound(i);
                    if(it != nx_y.end()){
                        int st=i-sx+1;
                        ret=min(ret,val_y[*it] - st+1);
                    }
                }
    
                if(lps_y[i]==sy){
                    auto it=nx_z.upper_bound(i);
                    if(it != nx_z.end()){
                        val_y[i-sy+1]=(*it)+sz-1;
                        nx_y.insert(i-sy+1);
                    }
                }
    
    
                if(lps_z[i]==sz){
                    nx_z.insert(i-sz+1);
                }
            }
    
            if(ret==n+1){
                ret=-1;
            }
    
    
    
    
    
            return ret;
    
            
            
            
    
        }
    };