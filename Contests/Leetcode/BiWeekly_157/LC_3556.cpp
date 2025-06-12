#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_value(string &num){
        ll val=0;
        for(auto ch:num){
            val=val*10+(ch-'0');
        }
        return val;
    }
    bool check_prime(ll val){
    
        if(val==1){
            return 0;
        }
        for(ll i=2;i*i<=val;i++){
            if(val%i==0){
                return 0;
            }
        }

        return 1;
    }
    long long sumOfLargestPrimes(string s) {
        set<ll> values;
        ll n=s.size();
        ll ans=0;

        for(ll i=0;i<n;i++){
            string curr;
            ll j=i;
            while(j<n){
                curr+=s[j];
                ll val=get_value(curr);
                if(check_prime(val)){
                    values.insert(val);
                }
                j++;
            }
        }

        ll rep=3;
        while(rep>0 && values.size()>0){
            ans=ans+(*(--values.end()));
            values.erase(--values.end());
            rep--;
        }

        return ans;

        
        
    }
};