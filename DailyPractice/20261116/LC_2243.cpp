#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string tmp;
            int i=0,n=s.size();
            
            while(i<n){
                int su=0,j=i,c=k;

                while(c-- and j<n){
                    su=su+(s[j]-'0');
                    j++;
                }

                tmp+=to_string(su);
                i=j;
            }
            
            s=tmp;
        }
        return s;
        
    }
};