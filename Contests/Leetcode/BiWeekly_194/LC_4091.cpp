#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<ll> atmost_d_prefix(string &s,ll d){
        vector<ll> cnt(26,0);
        ll n=s.size();
        vector<ll> ret(n,0);
        ll uniq=0,j=0;
        for(ll i=0;i<n;i++){
            cnt[s[i]-'a']++;
            if(cnt[s[i]-'a']==1)
                uniq++;
            
            while(uniq>d){
                cnt[s[j]-'a']--;
                if(cnt[s[j]-'a']==0)
                    uniq--;
                j++;
            }
            ret[i]=i-j+1;
        }
        return ret;
    }

    vector<ll> atmost_d_suffix(string &s,ll d){
        vector<ll> cnt(26,0);
        ll n=s.size();
        vector<ll> ret(n,0);
        ll uniq=0,j=n-1;
        for(ll i=n-1;i>=0;i--){
            cnt[s[i]-'a']++;
            if(cnt[s[i]-'a']==1)
                uniq++;
            
            while(uniq>d){
                cnt[s[j]-'a']--;
                if(cnt[s[j]-'a']==0)
                    uniq--;
                j--;
            }
            ret[i]=j-i+1;
        }
        return ret;
    }
    long long countMagicalPairs(string s) {
        ll n=s.size(),ans=0;

        for(ll dis=1;dis<=26;dis++){
            vector<ll> pref_d=atmost_d_prefix(s,dis);
            vector<ll> suff_d=atmost_d_suffix(s,dis);
            vector<ll> pref_d_=atmost_d_prefix(s,dis-1);
            vector<ll> suff_d_=atmost_d_suffix(s,dis-1);

            for(ll i=0;i+1<n;i++){
                ll exact_d_pref = pref_d[i]-pref_d_[i];
                ll exact_d_suff = suff_d[i+1]-suff_d_[i+1];
                ans=ans+exact_d_pref*exact_d_suff;
            }
        }

        return ans;
    }
};