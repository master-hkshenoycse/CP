#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        ll n=s.size();
        ll mod=1e9+7;
        vector<ll> powers(n+1,1);
        
        //storing the cumliative sum of powers
        //10^0+10^1+10^2+..
        for(ll i=1;i<=n;i++){
            powers[i]=(powers[i-1]*10)%mod;
        }
        
        for(ll i=1;i<=n;i++){
            powers[i]+=powers[i-1];
        }
        
        ll ans=0;
        //for a index in suffix numbers of ways it can be x power of 10 in representaion is equal to its index  
        for(ll i=n-1;i>=0;i--){
            ll max_poss=(n-i-1);
            ll mult=(s[i]-'0')*(i+1);
            mult%=mod;
            mult=(mult * powers[max_poss])%mod;
            
            ans=(ans+mult)%mod;
        }
        
        return ans;
    }
};
