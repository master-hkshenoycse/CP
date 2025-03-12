#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        
        string generateString(string str1, string str2) {
            int n=str1.size(),m=str2.size();
            int l=n+m-1;
            string sol(l,'?');
            vector<int> vis(l,false);
    
            for(int i=0;i<n;i++){
                if(str1[i]=='T'){
                    for(int j=0;j<m;j++){
                        if(sol[i+j]=='?'){
                            sol[i+j]=str2[j];
                            vis[i+j]=1;
                        }else{
                            if(sol[i+j] != str2[j]){
                                return "";
                            }else{
                                vis[i+j]=1;
                            }
                        }
                    }
                }
            }
    
            for(int i=0;i<l;i++){
                if(sol[i]=='?'){
                    sol[i]='a';
                }
            }
    
            for(int i=0;i<n;i++){
                if(str1[i]=='F'){
                    int n_eq=0;
                    for(int j=0;j<m;j++){
                        if(sol[i+j] != str2[j]){
                            n_eq=1;
                            break;
                        }
                    }
    
                    if(n_eq==0){
                        for(int j=m-1;j>=0;j--){
                            if(vis[i+j]==0 && sol[i+j]=='a' && str2[j]=='a'){
                                n_eq=1;
                                sol[i+j]='b';
                                break;
                            }
                        }
    
                        if(n_eq==0){
                            return "";
                        }
                    }
                }
            }
    
    
    
            return sol;
            
            
        }
    };