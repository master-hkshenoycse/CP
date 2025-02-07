#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string findValidPair(string s) {
        vector<int> cnt(10,0);
        for(auto ch:s){
            cnt[ch-'0']++;
        }   
        
        string ret;
        for(int i=0;i+1<s.size();i++){
            if(s[i] != s[i+1] and cnt[s[i]-'0']==s[i]-'0' and cnt[s[i+1]-'0']==s[i+1]-'0'){
                
                ret+=s[i];
                ret+=s[i+1];
                return ret;
            }
        }

        return ret;
    }
};