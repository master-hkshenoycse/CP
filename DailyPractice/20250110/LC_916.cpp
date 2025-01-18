#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int m=words2.size(),n=words1.size();
        vector<int> req(26,0);
        
        for(int i=0;i<m;i++){
            vector<int> cnt(26,0);
            for(auto ch:words2[i]){
                cnt[ch-'a']++;
            }
            for(int j=0;j<26;j++){
                req[j]=max(req[j],cnt[j]);
            }
        }
        
        vector<string> sol;
    
        
        for(int i=0;i<n;i++){
            vector<int> cnt(26,0);
            for(auto ch:words1[i]){
                cnt[ch-'a']++;
            }
            int f=1;
            for(int j=0;j<26;j++){
                if(cnt[j]<req[j]){
                    f=0;
                }
            }
            if(f){
                sol.push_back(words1[i]);
            }
        }
        
        return sol;
        
        
        
    }
};