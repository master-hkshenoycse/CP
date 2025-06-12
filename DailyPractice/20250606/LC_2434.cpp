#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string robotWithString(string s) {
            string sol,t;
            int n=s.size();
            
            vector<int> cnt(26,0);
            
            for(auto ch:s){
                cnt[ch-'a']++;
            }
            
            for(int i=0;i<n;i++){
                
                while(t.size()>0){
                    int mi_=-1;
                
                    for(int j=0;j<26;j++){
                        if(cnt[j]>0){
                            mi_=j;
                            break;
                        }
                    }
                    
                    if(t.size()>0 and t.back()-'a'<=mi_){
                        sol+=t.back();
                        t.pop_back();
                    }else{
                        break;
                    }
                }
                
                t+=s[i];
                cnt[s[i]-'a']--;
            
            }
            
            
            reverse(t.begin(),t.end());
            
            sol+=t;
            
            
        
            
            return sol;
        }
    };