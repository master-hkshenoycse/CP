#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        
        string sol;
        void rec(string &curr,int prev,string &pattern,int ind,vector<int> &vis){
            if(ind==pattern.size()){
                sol=min(sol,curr);
                return;
            }
            
            if(pattern[ind]=='I'){
                for(int i=prev+1;i<=9;i++){
                    
                    if(vis[i]){
                        continue;
                    }
                    vis[i]=1;
                    curr+=char('0'+i);
                    rec(curr,i,pattern,ind+1,vis);
                    vis[i]=0;
                    curr.pop_back();
                }
            }else{
                for(int i=prev-1;i>=1;i--){
                    if(vis[i]){
                        continue;
                    }
                    vis[i]=1;
                    curr+=char('0'+i);
                    rec(curr,i,pattern,ind+1,vis);
                    vis[i]=0;
                    curr.pop_back();
                }
            }
        }
        string smallestNumber(string pattern) {
            int n=pattern.size();
            sol.clear();
            
            for(int i=0;i<=n;i++){
                sol+='9';
            }
            vector<int> vis(10,0);
            string curr;
            for(int i=1;i<=9;i++){
                curr+=char('0'+i);
                vis[i]=1;
                rec(curr,i,pattern,0,vis);
                vis[i]=0;
                curr.pop_back();
            }
            
            
            
            return sol;
        }
    };