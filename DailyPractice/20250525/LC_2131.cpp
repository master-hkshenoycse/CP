#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int longestPalindrome(vector<string>& words) {
            map<string,int> help_neq,help_eq;
            
            for(auto w:words){
                if(w[0]==w[1]){
                    help_eq[w]++;
                }else{
                    help_neq[w]++;
                }
            }
            
            int ans=0;
            map<string,int>::iterator it;
             
            for(it=help_neq.begin();it!=help_neq.end();it++){
               
                if(it->second==0){
                    continue;
                }
                
                int x=it->second;
                string rev=it->first;
                reverse(rev.begin(),rev.end());
                
                if(help_neq.find(rev) != help_neq.end()){
                    int y=help_neq[rev];
                    ans=ans+min(x,y)*2;
                    help_neq[rev]=0;
                }
    
            }
            
            
            int is_odd=0;
            for(it=help_eq.begin();it!=help_eq.end();it++){
                if(it->second%2){
                    is_odd=1;
                }
                
                ans=ans+((it->second)/2)*2;
            }
            
            
            return (ans+is_odd)*2;
        }
    };