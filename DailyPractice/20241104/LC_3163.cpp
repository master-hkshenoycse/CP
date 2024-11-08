#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string compressedString(string word) {
        int i=0,n=word.size();
        string sol;
        
        while(i<n){
            int j=i,c=0;

            while(j<n and word[i]==word[j]){
                c++;
                j++;
            }
            
            int rep=c/9;
            int rem=c%9;
            for(int r=0;r<rep;r++){
                
                sol+=to_string(9);
                sol+=word[i];
            }

            if(rem>0){
                sol+=to_string(rem);
                sol+=word[i];
            }

            i=j;
        }

        return sol;
    }
};