#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        vector<int> cnt(26,0);
        vector<int> pref(26,0);
        
        
        int n=s.size();
        
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']++;
        }
        
        set<int> sol[26];
        for(int i=0;i<n;i++){
            
            for(int j=0;j<26;j++){
                int p=pref[j];
                int suff=cnt[j]-p-(s[i]-'a'==j);
                if(p>0 and suff>0){
                    sol[s[i]-'a'].insert(j);    
                }
                
            }
            
            pref[s[i]-'a']++;
        }
        
        int ans=0;
        for(int i=0;i<26;i++){
            ans=ans+(int)sol[i].size();
        }
        return ans;
        
    }
};