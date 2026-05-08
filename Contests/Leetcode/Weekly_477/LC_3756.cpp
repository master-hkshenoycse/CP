#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    ll modpow(ll a,ll n){
        ll ret=1;
        while(n>0){
            if(n%2)ret=(ret*a)%mod;
            a=(a*a)%mod;
            n/=2;
        }
        return ret;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        ll n=s.size();
        vector<ll> sod(n+1,0),nod(n+1,0),value(n+1,0);
        for(ll i=1;i<=n;i++){
            nod[i]=nod[i-1];
            value[i]=value[i-1];
            sod[i]=sod[i-1]+(s[i-1]-'0');
            sod[i]%=mod;
            if(s[i-1] !='0'){
                nod[i]++;
                value[i]=(value[i-1]*10+(s[i-1]-'0'))%mod;
            }
            //cout<<i<<" "<<nod[i]<<" "<<sod[i]<<" "<<value[i]<<endl;
        }
        vector<int> ret;

        for(auto q:queries){
            ll l=q[0]+1,r=q[1]+1;
            ll dig_cnt=nod[r]-nod[l-1];
            ll sod_q=(sod[r]-sod[l-1]+mod)%mod;
            ll value_prev=(value[l-1]*modpow(10,dig_cnt))%mod;
            ll value_curr=(value[r]-value_prev+mod)%mod;
            ret.push_back((value_curr*sod_q)%mod);
        }

        return ret;

    }
};