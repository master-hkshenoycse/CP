#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_sum(ll lo,ll hi,vector<ll> &csum){
        ll ret=csum[hi];
        if(lo-1>=0){
            ret-=csum[lo-1];
        }
        return ret;
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<ll> fruits_cnt(500005,0);
        for(auto p:fruits){
            cout<<p[0]<<" "<<p[1]<<endl;
            fruits_cnt[p[0]]+=p[1];
        }

        for(ll i=1;i<=500000;i++){
            fruits_cnt[i]+=fruits_cnt[i-1];
        }

        ll ans=0;

        for(ll i=0;i<=k;i++){
            ll lo=0,hi=0,cnt=0,rem_dist=0;

            //first move right
            cnt=0;
            lo=startPos;
            hi=lo+i;
            cnt+=get_sum(lo,hi,fruits_cnt);
            rem_dist=k-2*i;
            if(rem_dist > 0 && startPos>0){
                hi=startPos-1;
                lo=max(0ll,hi+1-rem_dist);

                cnt+=get_sum(lo,hi,fruits_cnt);
            }
            ans=max(ans,cnt);


            //first move left;
            cnt=0;
            hi=startPos;
            lo=max(0ll,hi-i);
            cnt+=get_sum(lo,hi,fruits_cnt);
            rem_dist = k-2*i;

            if(rem_dist>0){
                lo=startPos+1;
                hi=lo-1+rem_dist;
                cnt+=get_sum(lo,hi,fruits_cnt);
            }
            ans=max(ans,cnt); 

        }

        return ans;
    }
};