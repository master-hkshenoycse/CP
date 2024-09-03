#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string stringHash(string s, int k) {
        int n=s.size();
        string sol;
        
        for(int i=0;i<n;i+=k){
            int sum=0;
            for(int j=i;j<i+k;j++){
                sum=(sum+s[j]-'a')%26;
            }
            sol+=char('a'+sum);
        }
        
        
        return sol;
    }
};