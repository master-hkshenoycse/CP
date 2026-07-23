#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string,int> cnt;
        for(auto w:words)
            if(w.size()>=k)cnt[w.substr(0,k)]++;
        

        int ans=0;
        for(auto it:cnt)
            ans+=(it.second>1);
        
        return ans;
    }
};