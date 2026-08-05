#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        ll n=nums.size();
        vector<ll> csum(n,0);
        for(ll i=0;i<n;i++){
            csum[i]=nums[i];
            if(i-1>=0)
                csum[i]=csum[i-1]+csum[i];
        }

        ll ans=-1;
        ll prod=1;
        for(ll i=n-1;i>=0;i--){
            ll sum=0;
            if(i-1>=0){
                sum=csum[i-1];
            }

            if(prod>sum){
                return ans;
            }

            if(prod==sum){
                ans=i;
            }
            
            //cout<<prod<<" "<<sum<<" "<<nums[i]<<endl;;
            if(prod>sum/nums[i])
                return ans;

            prod=prod*nums[i]*1ll;
        }

        return -1;

    }
};