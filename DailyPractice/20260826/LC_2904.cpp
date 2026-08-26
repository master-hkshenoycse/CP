#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string sol;
        int n=s.size();
        for(int i=0;i<n;i++){
            string curr;
            int c1=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1'){
                    c1++;
                }
                curr+=s[j];
                if(c1==k){
                    if(sol.size()==0){
                        sol=curr;
                    }else if(sol.size()>curr.size()){
                        sol=curr;
                    }else if(sol.size()==curr.size()){
                        sol=min(sol,curr);
                    }
                }
                
                
                
                }
            }
        
        
        return sol;
    }
};