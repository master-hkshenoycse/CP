#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int lengthAfterTransformations(string s, int t) {
            vector<int> cnt(26,0);
            int mod=1e9+7;
            for(auto ch:s){
                cnt[ch-'a']++;
            }
    
            while(t--){
                vector<int> tmp(26,0);
                for(int i=1;i<26;i++){
                    tmp[i]=cnt[i-1];
                }
                tmp[0]=(tmp[0]+cnt[25])%mod;
                tmp[1]=(tmp[1]+cnt[25])%mod;
                cnt=tmp;
            }
    
            int ans=0;
            for(int i=0;i<26;i++){
                ans=ans+cnt[i];
                ans%=mod;
            }
            return ans;
        }
    };