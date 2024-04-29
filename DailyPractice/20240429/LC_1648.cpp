#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    //Brute force, is put the values of ball in max heap and get the best value
    //update the heap/
    //this will TLE, so use binary search
    ll mod=1e9+7;
    ll modpow(ll a,ll n){
        ll res=1;
        while(n>0){
            if(n%2){
                res=(res*a)%mod;
            }
            n/=2;
            a=(a*a)%mod;
        }
        return res;
    }
    ll get_sum(ll l,ll r){
        ll req=(r+l)%mod;
        req=(req * (r-l+1))%mod;
        req=(req * modpow(2,mod-2))%mod;
        return req;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        ll lo=0,hi=1e9+5,last_max=0;
        ll ans=0;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;

            ll cnt=0;
            for(auto e:inventory){
                cnt=cnt+max(0ll,e-mid+1);
            }

            if(cnt>=orders){
                last_max=max(last_max,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }

        last_max++;
        //cout<<last_max<<endl;
        sort(inventory.begin(),inventory.end());
        reverse(inventory.begin(),inventory.end());

        for(auto e:inventory){
            ll cnt_avail=max(0ll,e-last_max+1);
            ll taken=min(orders*1ll,cnt_avail);
            //cout<<e<<" "<<taken<<endl;
            ans=ans+get_sum(e-taken+1,e);
            ans%=mod;
            orders-=taken;Q
        }
        last_max--;
        if(orders>0){
            ans=(ans+orders*last_max)%mod;
        }
        return ans;

        
    }
};