#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        ll n=nums.size();
        vector<ll> prev_one(31,-1),next_one(31,n);
        vector<ll> L(n,0),R(n,n-1);

        for(int i=0;i<n;i++){
            for(int bit=0;bit<31;bit++){
                if((nums[i] & (1<<bit))==0){
                    L[i]=max(L[i],prev_one[bit]+1);
                }else{
                    prev_one[bit]=i;
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int bit=0;bit<31;bit++){
                if((nums[i] & (1<<bit))==0){
                    R[i]=min(R[i],next_one[bit]-1);
                }else{
                    next_one[bit]=i;
                }
            }
        }

        ll ans=0;
        map<int,int> last_same;
        for(int i=0;i<n;i++){
            ll l=L[i],r=R[i];
            if(last_same.find(nums[i]) != last_same.end())
                l=max(l, last_same[nums[i]]+1ll);
            last_same[nums[i]]=i;
            ans=ans+1LL*(i-l+1ll)*(r-i+1ll);
        }
        return ans;
    }
};