#include<bits/stdc++.h>
using namespace std;
#define ll  long long
class Solution {
public:
    ll modpow(ll a,ll n,ll mod){
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
    long long countSubstrings(string s) {
        ll ans=0;
        ll n=s.size();
        
        //divisible by 1/2/5;
        for(ll i=1;i<=n;i++){
            if(s[i-1]=='1' ||  s[i-1]=='2' ||  s[i-1]=='5'){
                ans=ans+i;
            }
        }
        
        //divisible by 3/6
        ll c0=1,c1=0,c2=0,c=0;
        for(ll i=1;i<=n;i++){
            c=(c+(s[i-1]-'0'))%3;
            
            if(s[i-1]=='3' ||  s[i-1]=='6'){
                if(c==0){
                    ans+=c0;
                }else if(c==1){
                    ans+=c1;
                }else{
                    ans+=c2;
                }
            }
            
            if(c==0){
                c0++;
            }else if(c==1){
                c1++;
            }else{
                c2++;
            }
        }
        
        
        //divisible by 8
        for(ll i=1;i<=n;i++){
            if(s[i-1]=='8'){
                if(i==1){
                    ans++;
                }else if(i==2){
                    if(((s[i-2]-'0')*10+(s[i-1]-'0'))%8==0){
                        ans++;
                    }
                    ans++;
                    
                }else{
                    ans++;
                    if(((s[i-3]-'0')*100+(s[i-2]-'0')*10+(s[i-1]-'0'))%8==0){
                        ans+=i-2;
                    }
                    
                    if(((s[i-2]-'0')*10+(s[i-1]-'0'))%8==0){
                        ans++;
                    }
                }
            }
        }
        
        //divisible by 4
        for(ll i=1;i<=n;i++){
            if(s[i-1]=='4'){
                if(i>1){
                    if(((s[i-2]-'0')*10+(s[i-1]-'0'))%4==0){
                        ans+=i-1;
                    }
                }
                ans++;
            }
        }
        
        
        
        //divisble by 9
        vector<ll> rem_cnt(9,0);
        rem_cnt[0]=1;
        c=0;
        for(ll i=1;i<=n;i++){
            c=(c+(s[i-1]-'0'))%9;
            if(s[i-1]=='9'){
                ans=ans+rem_cnt[c];
            }
            rem_cnt[c]++;   
        }
        
        
        //divisible by 7
        
        vector<ll> suff_rem(n+2,0);
        
        for(ll i=n;i>=1;i--){
            suff_rem[i]=(suff_rem[i+1]+(s[i-1]-'0')*modpow(10,n-i,7))%7;
        }
        
        vector<ll> seven_rem(7,0);
        
        for(ll i=1;i<=n;i++){
            seven_rem[suff_rem[i]]++;
            if(s[i-1]=='7'){
                ll sub=suff_rem[i+1];
                ll den=modpow(10,n-i,7);
                den=modpow(den,5,7);
                
                for(ll f=0;f<7;f++){
                    if((f*den-sub*den)%7==0){
                        ans=ans+seven_rem[f];
                    }
                }
                
                
            }
        }
        
        
        
        return ans;
    }
};