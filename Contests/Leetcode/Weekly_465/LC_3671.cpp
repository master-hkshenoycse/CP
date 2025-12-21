#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;
ll bit[70005];
void upd(ll ind,ll n,ll val){
    while(ind<=n){
        bit[ind]+=val;
        bit[ind]%=mod;
        bit[ind]=(bit[ind]+mod)%mod;
        ind+=(ind & (-ind));
    }
}

ll query(ll ind){
    ll ret=0;
    while(ind>0){
        ret=ret+bit[ind];
        ret%=mod;
        ind-=(ind & (-ind));
    }
    return ret;
}
class Solution {
public:
    
    int totalBeauty(vector<int>& nums) {
        ll n=nums.size();
        ll m = *max_element(nums.begin(),nums.end());
        vector<int> multiples[m+1];
        for(auto e:nums){
            for(int d=1;d*d<=e;d++){
                if(e%d==0){
                    multiples[d].push_back(e);
                    if(e/d !=d) multiples[e/d].push_back(e);
                }
            }
        }

        vector<ll> exact(m+1,0);
        ll ans=0;
        for(ll d=m;d>=1;d--){
            vector<ll> rev_ops;
            for(auto f:multiples[d]){
                ll ending_here = (query(f-1)+1)%mod;
                exact[d]=(exact[d]+ending_here)%mod;
                rev_ops.push_back(ending_here);
                upd(f,m,ending_here);
            }
            
            for(ll g=2*d;g<=m;g+=d){
                exact[d]=(exact[d]-exact[g]+mod)%mod;
            }

            //cout<<d<<" "<<exact[d]<<endl;
            ans=(ans+exact[d]*d)%mod;

            int c=0;
            for(auto f:multiples[d]){
                upd(f,m,-rev_ops[c]);
                c++;
            }
        }

        return ans;


        
    }
};