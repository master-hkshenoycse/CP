#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> b(26,0);
        for(auto ch:brokenLetters){
            b[ch-'a']=1;
        }
        
        int n=text.size();
        
        int i=0;
        int ans=0;
        while(i<n){
            int j=i;
            int c=0;
            
            while(j<n and text[j] != ' '){
                c=c+b[text[j]-'a'];
                j++;
            }
            
            if(c==0)ans++;
            i=j+1;
        }
        return ans;
        
    }
};