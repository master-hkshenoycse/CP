#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n=dominoes.size();
            
            vector<int> nearest_l(n,-1),nearest_r(n,-1);
            
            for(int i=0;i<n;i++){
                if(dominoes[i]=='R'){
                    nearest_r[i]=i;
                }else if(dominoes[i]=='L'){
                    nearest_r[i]=-1;            
                }else if(i>0){
                    nearest_r[i]=nearest_r[i-1];
                }
                
                
            }
    
            for(int i=n-1;i>=0;i--){
                if(dominoes[i]=='L'){
                    nearest_l[i]=i;
                }else if(dominoes[i]=='R'){
                    nearest_l[i]=-1;
                }else if(i<n-1){
                    nearest_l[i]=nearest_l[i+1];
                }
            }
            
            
            
            for(int i=0;i<n;i++){
               
                
                if(nearest_l[i]==-1 and nearest_r[i]==-1){
                    dominoes[i]='.';
                }else if(nearest_l[i]==-1){
                    dominoes[i]='R';
                }else if(nearest_r[i]==-1){
                    dominoes[i]='L';
                }else{
                    
                    int x=abs(i-nearest_r[i]);
                    int y=abs(i-nearest_l[i]);
                    
                    if(x==y){
                        dominoes[i]='.';
                    }else if(x>y){
                        dominoes[i]='L';
                    }else{
                        dominoes[i]='R';
                    }
                    
                }
            }
            
            return dominoes;
            
            
            
        }
    };