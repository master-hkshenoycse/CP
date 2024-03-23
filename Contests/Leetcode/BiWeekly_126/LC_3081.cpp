#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> cnt(26,0);
        for(auto ch:s){
            if(ch>='a' and ch<='z'){
                cnt[ch-'a']++;
            }
        }
        
        
        int n=s.size();
        vector<char> puts;
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                int min_cnt=INT_MAX;
                int ch=-1;
                for(int j=0;j<26;j++){
                    if(cnt[j]<min_cnt){
                        min_cnt=cnt[j];
                        ch=j;
                   }
                }
                puts.push_back(char('a'+ch));
                cnt[ch]++;
           }
        }
        
        sort(puts.begin(),puts.end());
        reverse(puts.begin(),puts.end());
        
        for(int i=0;i<n;i++){
            if(s[i]=='?'){
                s[i]=puts.back();
                puts.pop_back();
            }
        }
        
        return s;
    }
};