#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string,int> help;
        ll ret=0;
        string key;
        for(auto w:words){
            int n=w.size();
            for(int i=0;i+1<n;i++){
                int diff=(w[i]-w[i+1]+26)%26;
                key+=char('a'+diff);
            }

            ret=ret+help[key]*1ll;
            help[key]++;
            key.clear();

        }

        return ret;
    }
};