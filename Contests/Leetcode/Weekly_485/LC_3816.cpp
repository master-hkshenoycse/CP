#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        map<char,int> freq;
        string ret;
        for(auto ch:s)
            freq[ch]++;
        
        for(auto ch:s){
            while(ret.size()>0 && ret.back()>ch && freq[ret.back()]>1){
                freq[ret.back()]--;
                ret.pop_back();
            }
            ret.push_back(ch);
        }

        while(freq[ret.back()]>1){
            freq[ret.back()]--;
            ret.pop_back();
        }

        return ret;

    }
};