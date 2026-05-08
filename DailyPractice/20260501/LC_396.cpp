#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:

    int maxRotateFunction(vector<int>& nums) {
        ll n=nums.size();

        vector<ll> csum(2*n+1,0);
        ll s=0;

        for(ll i=1;i<=2*n;i++){
            
            if(i<=n)s+=nums[i-1],csum[i]=csum[i-1]+nums[i-1]*i;
            else csum[i]=csum[i-1]+nums[i-n-1]*i; 
        }

        

        ll ans=-1e18;

        for(ll i=1;i+n-1<=2*n;i++){
            ll st=i;
            ll en=i+n-1;

            ans=max(ans,(csum[en]-csum[st-1])-st*s);
        }



        return ans;
        
    }
};