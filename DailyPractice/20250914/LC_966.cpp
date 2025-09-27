#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    bool is_vowel(char ch){
        return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u'; 
    }
    
    char get_lower(char ch){
        if(ch>='a' and ch<='z')return ch;
        return char('a'+ch-'A');
    }
    
    string get_lcase(string s){
        int n=s.size();
        string y;
        
        for(int i=0;i<n;i++)y+=get_lower(s[i]);
        return y;
    }
    
    string rem_vowels(string s){
        int n=s.size();
        string y;
        
        for(int i=0;i<n;i++){
            if(is_vowel(s[i])){
                y+='$';
            }else{
                y+=s[i];
            }
        }
        return y;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n=wordlist.size();
        int m=queries.size();
        vector<string> sol(m);
        
        
        map<string,int> wordlist_small,vowels_removed,orig_string;
        for(int i=n-1;i>=0;i--){
            
            string l_q=get_lcase(wordlist[i]);
            string wo_vowel=rem_vowels(l_q);

            orig_string[wordlist[i]]=i;
            wordlist_small[l_q]=i;
            vowels_removed[wo_vowel]=i;
        }
        
        
        for(int i=0;i<m;i++){
            
            
           string l_q=get_lcase(queries[i]);
           string wo_vowel=rem_vowels(l_q);
            
           if(orig_string.find(queries[i]) != orig_string.end()){
               sol[i]=queries[i];
           }else if(wordlist_small.find(l_q) != wordlist_small.end()){
               sol[i]=wordlist[wordlist_small[l_q]];
           }else if(vowels_removed.find(wo_vowel) != vowels_removed.end()){
               sol[i]=wordlist[vowels_removed[wo_vowel]];
           }else{
                sol[i]="";   
           }
        

        }
        
        
        
        
        return sol;
    }
};