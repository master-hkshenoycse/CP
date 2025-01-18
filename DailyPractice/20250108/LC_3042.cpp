#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPrefixAndSuffix(string &s1,string &s2){
        int n=s1.size(),m=s2.size();
        if(n>m){
            return 0;
        }
        return s2.substr(0,n)==s1 and s2.substr(m-n,n)==s1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size(),ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=ans+isPrefixAndSuffix(words[i],words[j]);
            }
        }
        
        return ans;
    }
};