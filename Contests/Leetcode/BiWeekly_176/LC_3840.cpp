#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_optimal(vector<ll> &a){
        ll n=a.size();
        vector<ll> dp(n+1,0);
        for(ll i=0;i<n;i++){
            dp[i]=a[i];
            if(i-1>=0){
                dp[i]=max(dp[i],dp[i-1]);
            }

            if(i-2>=0){
                dp[i]=max(dp[i],dp[i-2]+a[i]);
            }
        }

        return dp[n-1];
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        ll i=0,n=nums.size(),ans=0;

        while(i<n){
            vector<ll> curr;
            ll j=i;
            while(j<n && colors[i]==colors[j]){
                curr.push_back(nums[j]);
                j++;
            }
            ans+=get_optimal(curr);
            i=j;
        }

        return ans;   
    }
};