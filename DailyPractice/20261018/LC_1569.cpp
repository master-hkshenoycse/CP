#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1000000007;
    ll fact[1005];
    ll invfact[1005];
    vector<ll> val;
    
    ll modpow(ll a,ll n){
        ll res=1;
        while(n){
            if(n%2)res=(res*a)%mod;
            a=(a*a)%mod;
            n/=2ll;
        }
       return res; 
    }
    
    ll ncr(ll n,ll r){
        if(r>n)return 0;
        ll x=fact[n];
        x=x*invfact[r];
        x%=mod;
        x*=invfact[n-r];
        x%=mod;
        return x;
    }
    
    ll get_sol(vector<ll> pro){
        if(pro.size()<=1)return 1;
        
        vector<ll> left,right;
        
        ll root=pro[0];
        ll n=pro.size();
        
        for(ll i=1;i<n;i++){
            if(pro[i]<root)left.push_back(pro[i]);
            else  right.push_back(pro[i]);
        }
        
        ll sol=ncr(n-1,left.size());
        
        sol=sol*get_sol(left);
        sol%=mod;
        sol=sol*get_sol(right);
        sol%=mod;
        return sol;
        
        
    }
    
    int numOfWays(vector<int>& nums) {
        fact[0]=fact[1]=1;
        invfact[0]=invfact[1]=1;
        for(ll i=2;i<=1000;i++){
            fact[i]=(fact[i-1]*i)%mod;
            invfact[i]=modpow(fact[i],mod-2);
        }
        int n=nums.size();
        for(ll i=0;i<n;i++)val.push_back(nums[i]);
        ll ans=get_sol(val);
        ans=(ans-1ll+mod)%mod;
        return ans;
        
    }
};