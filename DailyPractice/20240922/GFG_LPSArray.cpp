#include<bits/stdc++.h>
using namespace std;
int lps(string str) {
        // Your code goes here
        int n=str.size();
        vector<int> lps(n,0);
        int ans=0,len=0,i=1;
        
        while(i<n){
            if(str[i]==str[len]){
                len++;
                lps[i]=len;
                ans=max(ans,lps[i]);
                i++;
            }else{
                if(len!=0){
                    len=lps[len-1];
                }else{
                    i++;
                }
            }
        }
        
        return lps[n-1];
        
        
    }