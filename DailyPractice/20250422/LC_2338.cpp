#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
ll fact[100005];
ll dp[100000][25];
ll pre_done=0;

ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res * a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}
void pre_cum(){
    if(pre_done){
        return;
    }
    pre_done=1;
    fact[0]=1;
    for(ll i=1;i<=100000;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }

}

ll ncr(ll n,ll r){
    if(r>n)return 0;
    ll ret=fact[n];
    ret = (ret * modpow(fact[r],mod-2)) %mod;
    ret = (ret * modpow(fact[n-r],mod-2))%mod;
    return ret;
}


class Solution {
public:
    int idealArrays(int n, int maxValue) {

        pre_cum();

        for(int i=1;i<=maxValue;i++){
            for(int j=1;j<=min(n,14);j++){
                dp[i][j]=0;
            }
        }

        for(int i=1;i<=maxValue;i++){
            dp[i][1]=1;
            for(int j=2;j*i<=maxValue;j++){
                for(int k=1;k<=min(n,14);k++){
                    dp[i*j][k+1]+=dp[i][k];
                }
            }
        }

        ll res=0;
        for(ll i=1;i<=maxValue;i++){
            for(ll j=1;j<=min(n,14);j++){
                res=(res + ncr(n-1,n-j)*dp[i][j])%mod;
            }
        }
        return res;   
    }
};