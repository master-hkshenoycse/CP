#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    bool check(vector<ll> &req,vector<ll> &curr){
        for(ll i=0;i<26;i++){
            if(req[i]>curr[i]){
                return 0;
            }
        }
        return 1;
    }
    long long validSubstringCount(string word1, string word2) {
        ll n=word1.size(),m=word2.size();
        vector<ll> req(26,0);
        for(auto ch:word2){
            req[ch-'a']++;
        }

        vector<ll> curr(26,0);
        ll j=1,ans=0;
        for(ll i=1;i<=n;i++){
            curr[word1[i-1]-'a']++;
            while(j<=i and check(req,curr)==1){
                curr[word1[j-1]-'a']--;
                j++;
            }

            ans=ans+j-1;
        }

        return ans;

    }
};