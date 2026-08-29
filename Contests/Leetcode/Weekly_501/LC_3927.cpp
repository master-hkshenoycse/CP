#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll n=nums.size();
        map<ll,ll> vis;
        ll ans=0;

        for(ll i=0;i<n;i++){
            ll val=nums[i];
            for(ll j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    if(vis[j]==1)
                        val=min(val,j);
                    if(vis[nums[i]/j]==1)
                        val=min(val,nums[i]/j);
                }
            }
            ans+=val;
            //cout<<i<<" "<<nums[i]<<" "<<val<<endl;
            vis[nums[i]]=1;
        }
        return ans;
    }
};