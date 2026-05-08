#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        ll n=nums.size();
        vector<ll> suff_min(n),csum(n,0);
        for(ll i=0;i<n;i++){
            csum[i]=nums[i];
            if(i-1>=0)
                csum[i]+=csum[i-1];
        }

        for(ll i=n-2;i>=0;i--){
            suff_min[i]=nums[i+1];
            if(i+1<n-1)
                suff_min[i]=min(suff_min[i],suff_min[i+1]);
        }

        ll score=-1e18;
        for(ll i=0;i<n-1;i++)
            score=max(score,csum[i]-suff_min[i]);
        return score;
    }
};