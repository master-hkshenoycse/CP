#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
            int n=groups.size();
            int m=elements.size();
            
            map<int,int> help;
            for(int i=0;i<m;i++){
                if(help.find(elements[i])==help.end()){
                    help[elements[i]]=i;
                }
            }
            
            vector<int> ret(n,-1);
            
            for(int i=0;i<n;i++){
                int v=1e9;
                for(int j=1;j*j<=groups[i];j++){
                    if(groups[i]%j==0){
                        
                        if(help.find(j) != help.end()){
                            v=min(v,help[j]);
                        }
                        
                        if(help.find(groups[i]/j) != help.end()){
                            v=min(v,help[groups[i]/j]);
                        }
                        
                        
                    }
                }
                
                if(v<1e9){
                    ret[i]=v;
                }
                
            }
            
            return ret;
        }
    };