#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        vector<ll> dp_inc(r+1,0),dp_dec(r+1,0);

        for(ll i=1;i<=r;i++){
            if(i<l){
                dp_inc[i]=0;
                dp_dec[i]=0;
            }else{
                dp_inc[i]=(i-l)%mod;
                dp_dec[i]=(r-i)%mod;
            }
            dp_inc[i]=(dp_inc[i]+dp_inc[i-1])%mod;
            dp_dec[i]=(dp_dec[i]+dp_dec[i-1])%mod;
        }


        for(ll i=3;i<=n;i++){
            vector<ll> inc_tmp(r+1,0),dec_tmp(r+1,0);
            for(ll j=l;j<=r;j++){
                inc_tmp[j]=dp_dec[j-1];
                dec_tmp[j]=((dp_inc[r]-dp_inc[j])%mod+mod)%mod;
            }

            for(ll j=l;j<=r;j++){
                inc_tmp[j]=(inc_tmp[j]+inc_tmp[j-1])%mod;
                dec_tmp[j]=(dec_tmp[j]+dec_tmp[j-1])%mod;

                dp_inc[j]=inc_tmp[j];
                dp_dec[j]=dec_tmp[j];
            }
        }

        ll ans=(dp_inc[r]+dp_dec[r])%mod;
        return ans;

    }
};