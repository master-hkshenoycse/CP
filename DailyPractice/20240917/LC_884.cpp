
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> help1,help2;
        
        int n=s1.size();
        
        string y;
        for(int i=0;i<n;i++){
            if(s1[i]==' '){
                help1[y]++;
                y="";
            }else{
                y+=s1[i];
            }
        }
        
        help1[y]++;
        
        y="";
        n=s2.size();
        for(int i=0;i<n;i++){
            if(s2[i]==' '){
                help2[y]++;
                y="";
            }else{
                y+=s2[i];
            }
        }
        
        help2[y]++;
        
        vector<string> sol;
        for(auto it:help1){
            if(it.second>1)continue;
            if(help2.find(it.first) == help2.end()){
                sol.push_back(it.first);
            }
        }
        
        for(auto it:help2){
            if(it.second>1)continue;
            if(help1.find(it.first) == help1.end()){
                sol.push_back(it.first);
            }
        }
        
        return sol;
        
        
        
    }
};