#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string smallestSubsequence(string s) {
        string ret;
        vector<int> freq(26,0),seen(26,0);

        for(auto ch:s)
            freq[ch-'a']++;
        
        for(auto ch:s){
            freq[ch-'a']--;

            if(seen[ch-'a']>0)
                continue;

            while(ret.size()>0 && ret.back()>ch && freq[ret.back()-'a']>0){
                seen[ret.back()-'a']=0;
                ret.pop_back();
            }

            ret.push_back(ch);
            seen[ch-'a']++;

        }

        return ret;   
    }
};