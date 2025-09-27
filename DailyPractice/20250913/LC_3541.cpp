#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> cnt(26,0);
        for(auto ch:s){
            cnt[ch-'a']++;
        }

        int max_vowel=0,max_conson=0;
        for(char ch='a';ch<='z';ch++){
            if(ch=='a' || ch=='e' || ch =='i' || ch=='o' || ch=='u'){
                max_vowel=max(max_vowel,cnt[ch-'a']);
            }else{
                max_conson=max(max_conson,cnt[ch-'a']);
            }
        }

        return max_vowel+max_conson;
    }
};