#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        ll n=nums1.size();
        vector<ll> diff(n);
        
        vector<ll> cnt(100001,0);
        for(ll i=0;i<n;i++){
            diff[i]=abs(nums1[i]-nums2[i]);
            cnt[diff[i]]++;
        }
        
        ll tot=k1+k2;
        ll ans=0;
        
        for(int i=100000;i>=0;i--){
            if(cnt[i]==0){
                continue;
            }
            if(i==0){
                continue;
            }
            
            ll r=min(cnt[i],tot);
            cnt[i]-=r;
            cnt[i-1]+=r;
            tot-=r;
        }
        
        for(ll i=1;i<=100000;i++){
            ans=ans+cnt[i]*i*i;
        }
        
        return ans;
        
    }
};