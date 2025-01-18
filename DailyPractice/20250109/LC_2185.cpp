#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0,p=pref.size();
        for(auto s:words){
            if(s.size()>=pref.size()){
                if(s.substr(0,p)==pref)ans++;
            }
        }
        return ans;
    }
};