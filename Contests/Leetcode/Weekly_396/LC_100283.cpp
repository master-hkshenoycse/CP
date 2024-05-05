#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAnagramLength(string s) {
        int n=s.size();
        
        for(int i=1;i<=n;i++){
            if(n%i==0){
                
                vector<int> cnt_req(26,0);
            
                for(int j=0;j<i;j++){
                    cnt_req[s[j]-'a']++;
                }
                
                int f=1;
                for(int j=0;j<n;j+=i){
                    vector<int> tmp(26,0);
                    
                    for(int k=j;k<j+i;k++){
                        tmp[s[k]-'a']++;
                    }
                    
                    for(int k=0;k<26;k++){
                        if(cnt_req[k] != tmp[k]){
                            f=0;
                            break;
                        }
                    }
                    
                    if(f==0){
                        break;
                    }
                    
                }
                
                
                
                
                
                
                if(f){
                    return i;
                }
                
            }
        }
        
        return n;
    }
};