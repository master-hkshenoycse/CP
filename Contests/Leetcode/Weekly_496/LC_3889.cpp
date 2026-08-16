#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mirrorFrequency(string s) {
        map<char,int> freq;
        for(auto ch:s)
            freq[ch]++;
        
        int ans=0;
        for(char ch='0';ch<='4';ch++)
            ans=ans+abs(freq[ch]-freq['0'+('9'-ch)]);
        

        for(char ch='a';ch<='m';ch++){
            ans=ans+abs(freq[ch]-freq['a'+('z'-ch)]);
        }
        return ans;
    }
};