#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
            ll n=nums.size(),cost=0;
            
            //stores{ current, lesser cnt in suffix}
            //montonicity is maintained
            deque<pair<ll,ll> > dq;
            dq.push_front({nums[n-1],1});
            ll ans=1,right=n-1;

            for(ll left=n-2;left>=0;left--){
                ll curr=nums[left];
                ll cnt=1;
                while(dq.size()>0 and dq.back().first<curr){
                    ll ls=dq.back().first;
                    ll extra_cnt=dq.back().second;
                    cnt+=extra_cnt;
                    cost+=(curr-ls)*extra_cnt;
                    dq.pop_back();
                }

                dq.push_back({curr,cnt});

                while(cost>k){
                    ll more=dq.front().first;
                    ll extra_cnt=dq.front().second-1;
                    dq.pop_front();
                    cost-=(more-nums[right]);
                    right--;
                    if(extra_cnt>0){
                        dq.push_front({more,extra_cnt});
                    }
                }

                ans=ans+right-left+1;
            }

            return ans;
        }

};