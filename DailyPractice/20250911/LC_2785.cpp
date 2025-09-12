#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        vector<int> pos;
        vector<char> ch;
        
        for(int i=0;i<n;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                pos.push_back(i);
                ch.push_back(s[i]);
            }
            
            if(s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U'){
                pos.push_back(i);
                ch.push_back(s[i]);
            }
        }
        
        sort(ch.begin(),ch.end());
        for(int i=0;i<ch.size();i++){
            s[pos[i]]=ch[i];
        }
        
        return s;
    }
};