#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        int n=nums.size();
        set<ll> k_set;

        for(int i=0;i<n;i++){
            int val=nums[i];
            for(int j=2;j*j<=val;j++){
                if(val%j==0){
                    k_set.insert(j);
                    while(val%j==0)
                        val/=j;
                }
            }
            if(val>1)
                k_set.insert(val);
        }

        if(k_set.size()==0)
            k_set.insert(2);

        ll sc_max=-1e18,k_val=-1;
        for(auto k:k_set){
            ll csum_max=0,r=-1e18;
            for(auto e:nums){
                ll curr=e;
                if(e%k)
                    curr=-e;
                csum_max=max(csum_max+curr,curr);
                r=max(r,csum_max);
            }
            
            if(r>sc_max){ 
                sc_max=r;
                k_val=k;
            }

            //cout<<k<<" "<<r<<" "<<sc_max<<" "<<k_val<<endl;
        }

        ll ans=(k_val*sc_max)%mod;
        ans=(ans+mod)%mod;
        return ans;
    }
};