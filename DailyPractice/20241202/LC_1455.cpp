#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ind=0,i=0,n=sentence.size(),l=searchWord.size();

        while(i<n){
            
            if(sentence[i]==' '){
                i++;
            }else{
                string tmp;
                ind++;

                while(i<n and sentence[i]!=' '){
                    tmp+=sentence[i];
                    if(tmp.size()==l){
                        if(tmp==searchWord){
                            return ind;
                        }
                    }
                    i++;
                }
            }
        }

        return -1;
    }
};