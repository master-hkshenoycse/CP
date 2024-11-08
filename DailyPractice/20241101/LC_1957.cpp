#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        
        string sol;
        int i=0,j=0;
 
        
        
        while(i<n){
            int c=0;
            j=i;
            
            while(j<n and s[i]==s[j]){
                j=j+1;
                c++;
            }
            
            int rep=min(c,2);
            
            while(rep--){
                sol+=s[i];
            }
            
            i=j;
        }
    
        return sol;
        
    }
};