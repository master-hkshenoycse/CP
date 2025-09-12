#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll magic;
    ll mod=1e9+7;
    ll modpow(ll a,ll n){
        ll ret=1;
        while(n>0){
            if(n%2){
                ret=(ret * a)%mod;
            }
            a=(a*a)%mod;
            n/=2;
        }
        return ret;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        ll n=nums.size();
        magic = sqrt(n)+1;
        unordered_map<ll,vector<ll> > events;
        for(ll i=1;i<=magic;i++){
            for(ll j=0;j<n;j++){
                events[i].push_back(1);
            }
        }

        for(auto q:queries){
            ll l=q[0];
            ll r=q[1];
            ll k=q[2];
            ll v=q[3];

            if(k>magic){
                for(ll i=l;i<=r;i+=k){
                    nums[i]=(nums[i] * v)%mod;
                }
            }else{
                events[k][l]=(events[k][l] * v)%mod;
                ll r2=l+k*((r-l)/k+1);
                if(r2<n){
                    events[k][r2]=(events[k][r2] * modpow(v,mod-2))%mod;
                }
                //cout<<l<<" "<<r<<" "<<k<<" "<<r2<<endl;
            }
        }

        for(auto it:events){
            ll k = it.first;
            for(ll i=0;i<k;i++){
                ll curr=1;
                for(ll j=i;j<n;j+=k){
                    curr=(curr * it.second[j])%mod;
                    nums[j]=(nums[j] * curr)%mod;
                }
            }
        }
        
        ll ret =0;
        for(auto e:nums){
            ret=(ret ^ e);
        }

        return ret;
    }
};