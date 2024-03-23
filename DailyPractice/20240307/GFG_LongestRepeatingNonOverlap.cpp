#include<bits/stdc++.h>
using namespace std;

string longestSubstring(string s, int n) {
        // code here
        int maxLen=0;
        string ans="-1";
        
        int i=0,j=0;
        while(i<n and j<n){
            string subString=s.substr(i,j-i+1);
            
            if(s.find(subString,j+1) != string::npos){
                int len=subString.length();
                
                if(len>maxLen){
                    maxLen=len;
                    ans=subString;
                }
            }else{
                i++;
            }
            j++;
        }
        
        return ans;
    }