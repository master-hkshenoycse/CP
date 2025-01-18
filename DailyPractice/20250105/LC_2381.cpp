#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> f(n+2,0),b(n+2,0);
        
        for(auto s:shifts){
            if(s[2]==1){
                f[s[0]]++;
                f[s[1]+1]--;
            }else{
                b[s[0]]++;
                b[s[1]+1]--;
            }
        }
        
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            if(i-1>=0){
                f[i]+=f[i-1];
                b[i]+=b[i-1];
            }
            
            ch=(ch+f[i]-b[i])%26;
            ch=(ch+26)%26;
            s[i]=char('a'+ch);
        }
        
        return s;
    }
};