#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        
        map<string,int> help;
        
        for(auto s:arr){
            
            int sz=s.size();
            set<string> curr;
            
            for(int i=0;i<sz;i++){
                string tmp;
                for(int j=i;j<sz;j++){
                    tmp+=s[j];
                    curr.insert(tmp);
                }
            }
            
            for(auto s:curr){
                help[s]++;
            }
        }
        
        
        int n=arr.size();
        vector<string> sol(n);
        
        for(int k=0;k<n;k++){
            string s=arr[k];
            int sz=s.size();
            
            for(int i=0;i<sz;i++){
                string tmp;
                for(int j=i;j<sz;j++){
                    tmp+=s[j];
                    
                    if(help[tmp]==1){
                        if(sol[k].size()==0){
                            sol[k]=tmp;
                        }else if(sol[k].size()>tmp.size()){
                            sol[k]=tmp;
                        }else if(sol[k].size()==tmp.size()){
                            sol[k]=min(sol[k],tmp);
                        }
                        
                    }
                }
            
            }
            
        }
        
        return sol;
        
    
    }
};