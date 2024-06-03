#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        
        vector<int> is_del(n,0);

        vector<vector<int> > pos(26);
        
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                is_del[i]=1;
                for(int i=0;i<26;i++){
                    if(pos[i].size()>0){
                        is_del[pos[i].back()]=1;
                        pos[i].pop_back();
                        break;
                    }
                }
                
            }else{
                
                pos[s[i]-'a'].push_back(i);
                
            }
            
        }
        
        string sol;
        for(int i=0;i<n;i++){
            if(is_del[i]==0){
                sol+=s[i];
            }
        }
        
        return sol;
    }
};