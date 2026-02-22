#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        int las_len=0;
        
        int n=s.size();
        
        int i=0;
        
        while(i<n){
            int c=0;
            int j=i;
            while(j<n and s[i]==s[j]){
                j++;
                c++;
            }
            ans+=min(las_len,c);
            i=j;
            las_len=c;
        }
        return ans;
    }
};