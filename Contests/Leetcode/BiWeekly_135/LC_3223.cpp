#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt(26,0);
        for(auto ch:s){
            cnt[ch-'a']++;
        }
        
        int ans=0;
        for(int i=0;i<26;i++){
            while(cnt[i]>=3){
                cnt[i]-=2;
            }
            
            ans=ans+cnt[i];
        }
        
        return ans;
    }
};