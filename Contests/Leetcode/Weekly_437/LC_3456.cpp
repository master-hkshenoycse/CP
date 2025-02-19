#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool hasSpecialSubstring(string s, int k) {
            int i=0,n=s.size();
            while(i<n){
                int j=i,c=0;
                while(j<n and s[i]==s[j]){
                    j++;
                    c++;
                }
                
                if(c==k){
                    return 1;
                }
                i=j;
            }
            return 0;
        }
    };