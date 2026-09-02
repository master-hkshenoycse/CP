#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        ll n=nums2.size();
        ll seg_size=sqrt(n);
        vector<ll> nums2_ll(nums2.begin(), nums2.end());
        vector<map<ll,ll> > freq_segs;
        vector<ll> seg_starts,seg_ends;
        for(int i=0;i<n;i+=seg_size){
            int j=i,rem=seg_size;
            map<ll,ll> curr_freq;
            while(j<n && rem>0){
                curr_freq[nums2[j]]++;
                j++;
                rem--;
            }
            freq_segs.push_back(curr_freq);
            seg_starts.push_back(i);
            seg_ends.push_back(j-1);
        }

        int no_of_segs=freq_segs.size();
        vector<ll> segs_offset(no_of_segs,0);
        vector<int> ret;
        for(auto q:queries){
            if(q[0]==1){
                ll x=q[1],y=q[2],val=q[3];
                for(int i=0;i<no_of_segs;i++){
                    ll l=seg_starts[i];
                    ll r=seg_ends[i];
                    if(r<x || l>y){
                        continue;
                    }else if(l>=x && r<=y){
                        segs_offset[i]+=val;
                    }else{
                        l=max(l,x);
                        r=min(r,y);
                        for(int j=l;j<=r;j++){
                            freq_segs[i][nums2_ll[j]]--;
                            nums2_ll[j]+=val;
                            freq_segs[i][nums2_ll[j]]++;
                        }
                    }
                }
            }else{
                ll tot=q[1];
                int ans=0;
                for(auto val:nums1){
                    for(int i=0;i<no_of_segs;i++){
                        ll req=tot-val*1ll-segs_offset[i];
                        if(freq_segs[i].find(req) != freq_segs[i].end())
                            ans=ans+freq_segs[i][req];
                    }
                }
                ret.push_back(ans);
            }
        }

        return ret;
    }
};