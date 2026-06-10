#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_diff(ll l,ll r,vector<vector<ll> >&min_array,vector<vector<ll> >&max_array){
        ll len=r-l+1;
        ll ma=-1e18,mi=1e18;
        for(ll i=0;i<20;i++){
            if(len & (1<<i)){
                ma=max(ma,max_array[l][i]);
                mi=min(mi,min_array[l][i]);
                l+=(1ll<<i);
            }
        }

        return ma-mi;
    }
    void create_min_max_array(vector<int> &nums, vector<vector<ll> >&min_array,vector<vector<ll> >&max_array){
        ll n=nums.size();
        for(ll j=0;j<=20;j++){
            ll len= (1ll<<j);
            for(ll i=0;i<n;i++){
                if(i+len-1>=n){
                    break;
                }
                if(len==1){
                    min_array[i][0]=nums[i];
                    max_array[i][0]=nums[i];
                }else{
                    min_array[i][j]=min(min_array[i][j-1],min_array[i+len/2][j-1]);
                    max_array[i][j]=max(max_array[i][j-1],max_array[i+len/2][j-1]);
                }
            }
        }
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        ll n=nums.size();
        vector<vector<ll> >min_array(n+1,vector<ll> (25,1e18));
        vector<vector<ll> >max_array(n+1,vector<ll> (25,-1e18));
        create_min_max_array(nums,min_array,max_array);

        priority_queue<pair<ll,pair<ll,ll> > > pq;
        set<pair<ll,ll> > vis;
        pq.push({get_diff(0,n-1,min_array,max_array),{0,n-1}});
        vis.insert({0,n-1});

        ll ret=0;
        while(k--){
            auto curr=pq.top();
            pq.pop();
            ret=ret+curr.first;
            ll l=curr.second.first;
            ll r=curr.second.second;
            if(l+1<=r && vis.find({l+1,r})==vis.end()){
                pq.push({get_diff(l+1,r,min_array,max_array),{l+1,r}});
                vis.insert({l+1,r});
            }

            if(l<=r-1 && vis.find({l,r-1})==vis.end()){
                pq.push({get_diff(l,r-1,min_array,max_array),{l,r-1}});
                vis.insert({l,r-1});
            }
        }

        return ret;


    }
};