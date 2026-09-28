#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        ll n=nums.size();
        vector<ll> csum(2*n,0);
        ll tot=0;
        for(ll i=0;i<2*n;i++){
            if(i<n)
                csum[i]=nums[i];
            else
                csum[i]=nums[i-n];
            
            if(i-1>=0)
                csum[i]+=csum[i-1];
        }

        tot=csum[2*n-1]/2;
        int ans=0;

        for(ll i=0;i<n;i++){
            ll req=csum[i+n/2-1];
            if(i-1>=0)
                req-=csum[i-1];
            //cout<<tot<<" "<<req<<endl;
            if(req*2 > tot)
                ans++;
        }

        return ans;

    }
};