#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool isValid(string word) {
            int vowel=0,consonant=0;
            if(word.size()<3){
                return 0;
            }
            
            for(auto ch:word){
                if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u'){
                    vowel++;
                    continue;
                }
                
                if(ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U'){
                    vowel++;
                    continue;
                }
                
                if(ch>='a' and ch<='z'){
                    consonant++;
                    continue;
                }
                
                if(ch>='A' and ch<='Z'){
                    consonant++;
                    continue;
                }
                
                if(ch=='@' or ch=='#' or ch=='$'){
                    return 0;
                }
            }
            
            return vowel>0 and consonant>0;
        }
    };class Solution {
        public:
            bool isValid(string word) {
                int vowel=0,consonant=0;
                if(word.size()<3){
                    return 0;
                }
                
                for(auto ch:word){
                    if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u'){
                        vowel++;
                        continue;
                    }
                    
                    if(ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U'){
                        vowel++;
                        continue;
                    }
                    
                    if(ch>='a' and ch<='z'){
                        consonant++;
                        continue;
                    }
                    
                    if(ch>='A' and ch<='Z'){
                        consonant++;
                        continue;
                    }
                    
                    if(ch=='@' or ch=='#' or ch=='$'){
                        return 0;
                    }
                }
                
                return vowel>0 and consonant>0;
            }
        };