#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll mod=1e9+7;

    ll modpow(ll a,ll n){
        ll res=1;
        while(n>0){
            if(n%2){
                res=(res*a)%mod;
            }
            a=(a*a)%mod;
            n/=2;
        }
        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        ll n=nums.size(),ans=0;


        for(int i=0;i<n;i++){
            if(nums[i]*2>target){
                break;
            }
            ll ind=upper_bound(nums.begin()+i,nums.end(),target-nums[i])-nums.begin();
        ///    cout<<i<<" "<<ind<<" ";
            int cnt=ind-i-1;
         //   cout<<cnt<<endl;

            ans=ans+modpow(2,cnt);
            ans%=mod;
        }
        return ans;

    }
};