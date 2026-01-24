#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        int n=s.size();
        vector<int> cnt(26,0);

        for(auto ch:s){
            cnt[ch-'a']++;
        }
        
        map<int,string> help;
        for(char ch='a';ch<='z';ch++){
            if(cnt[ch-'a'] > 0)help[cnt[ch-'a']]+=ch;
        }
        int cnt_dis=0;
        string ret;
        for(auto it:help){
            if(cnt_dis <= it.second.size()){
                cnt_dis = it.second.size();
                ret=it.second;
            }
        }

        return ret;

    }
};