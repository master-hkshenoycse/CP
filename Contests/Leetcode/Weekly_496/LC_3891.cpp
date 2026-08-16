#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        ll n=nums.size();

        vector<ll> cost(n,1e18);
        for(ll i=1;i<n-1;i++)
            cost[i]=max(0,max(nums[i+1],nums[i-1])+1-nums[i]);
        
        ll ret=0;
        if(n%2==1){
            for(ll i=1;i<n-1;i+=2)
                ret=ret+cost[i];
        }else{
            vector<ll> suff_odd(n,0),suff_even(n,0);
            for(ll i=n-2;i>=1;i--){
                suff_odd[i]=suff_odd[i+1];
                suff_even[i]=suff_even[i+1];
                if(i%2==0)
                    suff_even[i]+=cost[i];
                else
                    suff_odd[i]+=cost[i];
            }

            ll pref_odd=0,pref_even=0;
            ret=1e18;
            for(ll i=1;i<n-1;i++){
                if(i%2==0){
                    ret=min(ret,pref_odd+suff_even[i+1]);
                    pref_even+=cost[i];
                }else{
                    ret=min(ret,min(pref_odd,pref_even)+suff_even[i+1]);
                    pref_odd+=cost[i];
                }
            }
        }

        return ret;
    }
};