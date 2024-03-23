#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int l=0;
        int r=n-1;
        
        
        
        while(1){
            if(l==r)return 1;
            if(l>r){
                return 0;
            }
            if(s[l] != s[r]){
                return r-l+1;
            }
            char ch=s[l];
            
            
            while(l<n and s[l]==ch)l++;
            while(r>=0 and s[r]==ch)r--;
        }
        return 0;
    }
};