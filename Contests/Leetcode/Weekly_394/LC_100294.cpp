#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> cnt_lower(26,0),cnt_upper(26,0);
        for(auto ch:word){
            if(ch>='a' and ch<='z')cnt_lower[ch-'a']++;
            else cnt_upper[ch-'A']++;
        }
        
        int ans=0;
        for(int i=0;i<26;i++){
            if(cnt_lower[i]>0 and cnt_upper[i]>0){
                ans++;
            }
        }
        return ans;
    }
};