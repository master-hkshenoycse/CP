#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int c=0;
        int ans=0;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(c>0)ans=c;
                c=0;
                
            }
            else{
                c++;
            }
            
        }
        if(c>0)ans=c;
        return ans;
    }
};