#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_gain(ll st,ll en,ll k,ll coins){
        ll len_used=max(0ll,en-st+1ll);
        len_used=min(len_used,k*1ll);
        return len_used*coins;
    }

    ll get_next_ind(vector<vector<int> > &coins,ll start_ind,ll k){
        ll n=coins.size();
        ll lo=start_ind,hi=n-1,ret=start_ind-1;
        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            if(coins[mid][1]-coins[start_ind][0]+1ll<=k){
                ret=max(ret,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ret;
    }

    ll get_sum(ll l,ll r,vector<ll> &coin_sum){
        ll ret=coin_sum[r];
        if(l-1>=0){
            ret-=coin_sum[l-1];
        }
        return ret;
    }

    ll get_prev_ind(vector<vector<int> > &coins,ll start_ind,ll k){
        ll n=coins.size();
        ll lo=0,hi=start_ind,ret=start_ind+1;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;

            if(coins[start_ind][1]-coins[mid][0]+1<=k){
                ret=min(ret,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ret;
    }


    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(),coins.end());
        ll n=coins.size();
        vector<ll> coin_sum(n,0);
        ll ans=0;

        for(ll i=0;i<n;i++){
            coin_sum[i]=coins[i][2]*1ll*(coins[i][1]-coins[i][0]+1ll);
            if(i>0){
                coin_sum[i]+=coin_sum[i-1];
            }
        }

        for(int i=0;i<n;i++){
            ans=max(ans,get_gain(coins[i][0],coins[i][1],k,coins[i][2]));
            ll nxt_ind=get_next_ind(coins,i,k);
            ll prev_ind=get_prev_ind(coins,i,k);
            
            if(nxt_ind >= i){
                ll coins_gain=get_sum(i,nxt_ind,coin_sum);
                ll len_rem=k-(coins[nxt_ind][1]-coins[i][0]+1);
                if(nxt_ind+1<n && len_rem>0){
                    coins_gain+=get_gain(coins[nxt_ind+1][0],coins[nxt_ind][1]+len_rem,k,coins[nxt_ind+1][2]);
                }
                //cout<<i<<" "<<nxt_ind<<" "<<coins_gain<<endl;
                ans=max(ans,coins_gain);
            }

            if(prev_ind<=i){
                ll coins_gain=get_sum(prev_ind,i,coin_sum);
                ll len_rem=k-(coins[i][1]-coins[prev_ind][0]+1);
                if(prev_ind-1>=0 && coins[prev_ind][0]-len_rem<=coins[prev_ind-1][1]){
                    coins_gain+=get_gain(coins[prev_ind][0]-len_rem,coins[prev_ind-1][1],k,coins[prev_ind-1][2]);
                }
                //cout<<i<<" "<<prev_ind<<" "<<coins_gain<<endl;
                ans=max(ans,coins_gain);
            }
        }

        return ans;
    }
};