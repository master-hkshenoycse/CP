#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int lps[1005];
    void upd(string s){
            int len = 0;
            int M=s.size();
            lps[0] = 0; 
            for(int i=0;i<M;i++)lps[i]=0;
      
            int i = 1;
            while (i < M) {
                if (s[i] == s[len]) {
                    len++;
                    lps[i] = len;
                    i++;
                }else{
                   if (len != 0){
                        len = lps[len - 1];
                    }
                    else{
                        lps[i] = 0;
                        i++;
                    }
                }
           }
     }
        
    int KMPSearch(string pat, string txt){
        int M = pat.size();
        int N = txt.size();
      
        
        int i = 0;
        int j = 0;
        while (i < N) {
            
            if (pat[j] == txt[i]){
                j++;
                i++;
            }
      
            if (j == M) {
                return i-j;
            }else if (i < N && pat[j] != txt[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return -1;
    }
     
    string removeOccurrences(string s, string part) {
            
        int n=s.size();
        int m=part.size();
        
        
        while(1){
            
            int n=s.size();
            int m=part.size();
            int ind=-1;
            
            for(int i=0;i<n-m+1;i++){
                
                int f=1;
                
                for(int j=0;j<m;j++){
                    if(s[i+j] != part[j]){
                        f=0;
                        break;
                    }
                }
                
                if(f){
                    ind=i;
                    break;
                }
            }
            
            if(ind==-1)break;
            
            string y;
            for(int i=0;i<n;i++){
                if(i>=ind and i<=ind+m-1)continue;
                y+=s[i];
            }
            s=y;
        }
        
        
        
        return s;
        
    }
    };