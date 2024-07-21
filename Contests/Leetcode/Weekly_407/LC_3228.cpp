#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxOperations(string s) {
        int ans=0,i=0,n=s.size(),c_one=0;
        while(i<n){
            int j=i,c=0;
            while(j<n and s[i]==s[j]){
                c++;
                j++;
            }
            if(s[i]=='1'){
                ans=ans+c_one;
                c_one+=c;
            }

            i=j;
        }

        if(s.back()=='0'){
            ans=ans+c_one;
        }

        

        return ans;
    }
};