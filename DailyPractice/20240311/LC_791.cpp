#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> cnt(26,0),ord(26,-1);
        int m=order.size();

        for(int i=0;i<m;i++){
            ord[order[i]-'a']=i;
        }

        for(auto ch:s){
            cnt[ch-'a']++;
        }

        vector<vector<int> > a;
        for(int i=0;i<26;i++){
            a.push_back({ord[i],i,cnt[i]});
        }

        sort(a.begin(),a.end());
        int c=0;
        for(int i=0;i<26;i++){
            while(a[i][2]--){
                s[c++]=char('a'+a[i][1]);
            }
        }

        return s;
    }
};