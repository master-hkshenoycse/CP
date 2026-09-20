#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    void upd(vector<ll> &bit,ll ind,ll n,ll val){
        while(ind<=n){
            bit[ind]+=val;
            ind+=(ind & (-ind));
        }
    }
    ll query(vector<ll> &bit,ll ind){
        ll ret=0;
        while(ind>0){
            ret=ret+bit[ind];
            ind-=(ind & (-ind));
        }
        return ret;
    }
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        ll n=nums.size();
        ll c_e=0,c_o=0;
        vector<ll> prefix_(n+1,0);
        map<ll,ll> hsh;
        hsh[0]=1;

        for(ll i=1;i<=n;i++){
            if(nums[i-1]%2==0)
                c_e++;
            else
                c_o++;

            prefix_[i]=b*c_e-a*c_o;
            hsh[prefix_[i]]++;
        }

        vector<ll> bit_(n+2,0);
        ll c=1;
        for(auto &it:hsh)
            it.second=c,c++;

        ll ans=0;

        upd(bit_,hsh[0],n+1,1);

        for(ll i=1;i<=n;i++){
            //cout<<i<<" "<<hsh[prefix_[i]]<<endl;
            ans=ans+i-query(bit_,hsh[prefix_[i]]-1);
            upd(bit_,hsh[prefix_[i]],n+1,1);
        }
        
        return ans;
    }
};