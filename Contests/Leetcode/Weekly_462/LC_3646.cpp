#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_value(string &s){
        ll ret=0;
        for(auto ch:s){
            ret=ret*10+(ch-'0');
        }
        return ret;
    }
    long long specialPalindrome(long long n) {
        ll ans=1e18;
        for(ll i=1;i<1024;i++){
            ll odd_dig=0,tot_dig=0;
            for(ll j=1;j<10;j++){
                if(i & (1<<j)){
                    tot_dig+=j;
                    if(j%2){
                        odd_dig++;
                    }
                }
            }

            if(odd_dig>1){
                continue;
            }

            if(tot_dig>18){
                continue;
            }

            vector<ll> dig;
            string curr;

            for(ll i=1;i<=tot_dig;i++){
                curr+='9';
            }
            for(ll j=1;j<10;j++){
                if(i & (1<<j)){
                    ll rep=j;
                    if(j%2){
                        curr[tot_dig/2]=char('0'+j);
                        rep--;
                    }

                    for(ll cnt=1;cnt<=rep/2;cnt++){
                        dig.push_back(j);
                    }
                }
            }

            do{

                for(ll i=0;i<dig.size();i++){
                    curr[i]=char('0'+dig[i]);
                    curr[curr.size()-i-1]=curr[i];
                }

                ll val = get_value(curr);
                if(val>n){
                    ans=min(ans,val);
                }

            }while(next_permutation(dig.begin(),dig.end()));
        }

        return ans;
    }
};