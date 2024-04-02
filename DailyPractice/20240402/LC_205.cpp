#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //one to one mapping bwteen characters
    bool isIsomorphic(string s, string t) {
        map<char,int> help;
        set<int> adj1[256],adj2[256];
        int n=s.size();
        for(int i=0;i<256;i++){
            help[char(i)]=i;
        }
        
        for(int i=0;i<n;i++){
            adj1[help[t[i]]].insert(help[s[i]]);
            adj2[help[s[i]]].insert(help[t[i]]);
        }
        
        for(int i=0;i<256;i++){
            if(adj1[i].size()>1 or adj2[i].size()>1){
                return 0;
            }
        }
        
        
        
        
        return 1;
    }
};