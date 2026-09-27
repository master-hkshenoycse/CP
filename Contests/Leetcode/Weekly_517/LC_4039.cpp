#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    ll modpow(ll a,ll n){
        ll res=1;
        while(n>0){
            if(n%2)
                res=(res*a)%mod;
            n/=2;
            a=(a*a)%mod;
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        ll ret=0;   

        for(auto n:nums){
            ll width = (n%10);
            string di= to_string(n/10);
            ll x=0,y=0;

            for(ll i=0;i<di.size();i++){
                if(i<width)
                    x=x*10+(di[i]-'0');
                else
                    y=y*10+(di[i]-'0');
            }

            ret=ret+modpow(x,y);
            ret%=mod;
        }

        return ret;
    }
};