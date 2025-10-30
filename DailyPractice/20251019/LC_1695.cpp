#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     string ans;
     map<string,int> help;
    
     void rec(string s,int a,int b){
         if(help[s]){
             ans=min(ans,s);
             return;
         }
         help[s]=1;
         string tmp=s;
         int n=s.size();
         for(int i=1;i<n;i+=2){
                int dig=tmp[i]-'0';
                dig=(dig+a)%10;
                tmp[i]=char('0'+dig);
        }
        rec(tmp,a,b);
        ans=min(ans,tmp); 
         
        tmp="";
        
        for(int i=b;i<n;i++)tmp+=s[i];
        for(int i=0;i<b;i++)tmp+=s[i];
        
        rec(tmp,a,b);
        ans=min(ans,tmp);
         
         
         
     }
    string findLexSmallestString(string s, int a, int b) {
       
        int n=s.size();
        for(int i=0;i<n;i++)ans+='9';
        
        rec(s,a,b);
        return ans;   
    }
};