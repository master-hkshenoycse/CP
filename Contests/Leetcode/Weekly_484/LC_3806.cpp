#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        ll ret=0,n=nums.size();
        for(ll i=30;i>=0;i--){
            vector<pair<ll,ll> > req;
            vector<int> nx;
            
            n=nums.size();
            ll all_bit=(1ll<<i)-1;
            for(int j=0;j<n;j++){
                ll e=nums[j];
                if(e & (1ll<<i)){
                    nx.push_back(nums[j]);
                }else{
                    req.push_back({(1ll<<i)-(e&all_bit),j});
                }
            }

            if(nx.size()>=m){
                ret+=(1ll<<i);
                nums=nx;
            }else{
                sort(req.begin(),req.end());
                ll ex=m-nx.size();
                ll tot=0;
                for(ll j=0;j<ex;j++)
                    tot+=req[j].first;

                if(tot<=k){
                    ret+=(1ll<<i);
                    k-=tot;
                    for(ll j=0;j<ex;j++){
                        nums[req[j].second]+=req[j].first;
                        nx.push_back(nums[req[j].second]);
                    }
                    nums=nx;
                }

                
                
            }
        }
        return ret;
    }
};