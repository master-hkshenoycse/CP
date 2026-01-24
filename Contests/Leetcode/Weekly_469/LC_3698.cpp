#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        ll n=nums.size();
        vector<ll> right_valid(n,0);
        ll tot_sum=0;

        for(ll i=n-1;i>=0;i--){
            tot_sum+=nums[i];
            if(i+1==n ||  (right_valid[i+1]==1 && nums[i+1]<nums[i])){
                right_valid[i]=1;
            }

        }

        ll ans=1e18;
        ll curr_sum=0;

        for(ll i=0;i+1<n;){
            curr_sum+=nums[i];
            //cout<<i<<" "<<right_valid[i+1]<<endl;
            if(right_valid[i+1]){
                ans=min(ans,abs(curr_sum-(tot_sum-curr_sum)));
            }
            if(nums[i+1]>nums[i]){
                i++;
            }else{
                break;
            }
        }

        if(ans==1e18){
            ans=-1;
        }


        return ans;

    }
};