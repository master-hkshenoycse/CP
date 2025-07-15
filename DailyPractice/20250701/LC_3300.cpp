#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int possibleStringCount(string word) {
            int i=0,n=word.size(),ans=1;
            while(i<n){
                int c=0,j=i;
                while(j<n and word[i]==word[j]){
                    j++;
                    c++;
                }
                i=j;
    
                ans=ans+c-1;
            }
            return ans;
        }
    };