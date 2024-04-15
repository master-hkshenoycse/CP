#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        ll lo=0,hi=1e18,ans=hi;//binary search on answer
        //smallest number in which <=k numbers can be created by coins
        //use inclusion exclusion
        ll n=coins.size();
        ll lim=(1ll<<n);
        while(hi>=lo){
            ll cnt=0;
            ll mid=(hi+lo)/2ll;

            for(ll i=1;i<lim;i++){
                ll c=0,mul=1;

                for(ll j=0;j<n;j++){
                    if(i & (1ll<<j)){
                        c++;
                        mul=(mul * coins[j])/__gcd(mul,coins[j]*1ll);
                        if(mul>mid){
                            break;
                        }
                    }
                }

                if(c%2){
                    cnt=cnt+mid/mul;
                }else{
                    cnt=cnt-mid/mul;
                }

            }

            //cout<<mid<<" "<<cnt<<endl;


            if(cnt>=k){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ans;
    }
};