#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long numOfSubsequences(string s) {
        ll n = s.size();
        vector<ll> pref_l(n+1,0),suff_t(n+1,0);
        ll ct=0,lc=0;
        for(ll i=1;i<=n;i++){
            pref_l[i]=pref_l[i-1]+(s[i-1]=='L');
            if(s[i-1]=='C'){
                lc+=pref_l[i];
            }
        }

        for(ll i=n;i>=1;i--){
            suff_t[i]=(s[i-1]=='T');
            if(i+1<=n){
                suff_t[i]+=suff_t[i+1];
            }

            if(s[i-1]=='C'){
                ct+=suff_t[i];
            }
        }

       

        ll ans=0,max_gain=max(lc,ct);
        for(ll i=1;i<=n;i++){
            if(s[i-1]=='C'){
                ans=ans+pref_l[i]*suff_t[i];
            }

            max_gain=max(max_gain,pref_l[i]*suff_t[i]);
        }


        return ans+max_gain;


    }
};