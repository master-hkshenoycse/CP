#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_contri(ll n){
        return (n*n+n)/2ll;
    }
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        ll n=nums.size();
        vector<ll> prefix_stable_cnt(n+1,0),grp_idx(n+1,0);
        ll running_inc=0;
        vector<ll> grp_start,grp_cnt;
        ll grp_no=0;
        for(ll i=1;i<=n;i++){
            prefix_stable_cnt[i]+=prefix_stable_cnt[i-1];
            if(i-1>0 && nums[i-1]>=nums[i-2]){
                running_inc++;
            }else{
                running_inc=1;
                grp_no++;
                grp_start.push_back(i);
                grp_cnt.push_back(0);
            }
            prefix_stable_cnt[i]+=running_inc;
            grp_idx[i]=grp_no;
            //cout<<i<<" "<<prefix_stable_cnt[i]<<" "<<grp_idx[i]<<endl;
            grp_cnt.back()++;
        }

        vector<ll> ret;

        for(auto q:queries){
            ll l=q[0]+1,r=q[1]+1;

            ll tot=prefix_stable_cnt[r]-prefix_stable_cnt[l-1];
            ll start_trail=grp_start[grp_idx[l]-1];
            if(start_trail<l){
                ll tot_grp=grp_cnt[grp_idx[l]-1];
                ll before_query=l-start_trail;
                ll in_query=min(r-l+1,tot_grp-before_query);
                //cout<<"Query comp "<<tot<<" "<<tot_grp<<" "<<before_query<<" "<<in_query<<endl;
                ll current=(get_contri(in_query+before_query)-get_contri(before_query));
                tot-=current;
                tot+=get_contri(in_query);
            }

            ret.push_back(tot);
        }

        return ret;



    }
};