#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.size(),m=t.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]==t[c]){
                c++;
            }
            
            if(c==m){
                return 0;
            }
        }
        return m-c;
    }
};