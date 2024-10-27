#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    int possibleStringCount(string word, int k) {
 
        ll i=0,n=word.size(),segs=0;
        if(n<k){
            return 0;
        }

        vector<ll> extra;
        while(i<n){
            ll j=i,c=0;
            while(j<n and word[i]==word[j]){
                c++;
                j++;
            }
            segs++;
            extra.push_back(c-1);
            i=j;
        }
        ll tot_ways=1;
        for(auto e:extra){
            tot_ways=(tot_ways * (e+1))%mod;
        }


        if(segs>=k){
            return tot_ways;
        }
        ll ex=k-segs;

        vector<ll> dp(ex+2,1);
        

        for(ll i=0;i<segs;i++){
            vector<ll> tmp_dp(ex+2,0);
            for(ll j=0;j<ex;j++){
                ll hi=j;
                ll lo=max(0ll,j-extra[i]);
                ll y=dp[hi];
                if(lo-1>=0){
                    y=(y-dp[lo-1]+mod)%mod;
                }
                tmp_dp[j]=y;
            }
            for(ll j=0;j<ex;j++){
                dp[j]=tmp_dp[j];
                if(j-1>=0){
                    dp[j]=(dp[j]+dp[j-1])%mod;
                }
            }

        }
        
        tot_ways=(tot_ways-dp[ex-1]+mod)%mod;
        

        return tot_ways;


    }
};