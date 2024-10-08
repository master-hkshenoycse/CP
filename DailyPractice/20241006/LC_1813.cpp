#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> get_words(string &s){
        string curr;
        int n=s.size();
        vector<string> ret;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                ret.push_back(curr);
                curr.clear();
            }else{
                curr+=s[i];
            }
        }

        if(curr.size()>0){
            ret.push_back(curr);
        }

        return ret;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> w1=get_words(sentence1);
        vector<string> w2=get_words(sentence2);

        if(w1.size()>w2.size()){
            swap(w1,w2);
        }

        int n=w1.size(),m=w2.size();
        int pref_match=0,suff_match=0;
        int match=0;
        while(pref_match<n){
            if(w1[pref_match]==w2[pref_match]){
                match++;
                pref_match++;
            }else{
                break;
            }
        }

        if(pref_match==n){
            return 1;
        }

        while(suff_match<n){
            if(w1[n-suff_match-1]==w2[m-suff_match-1]){
                match++;
                suff_match++;
            }else{
                break;
            }
        }

        

        return match>=n;
    }
};