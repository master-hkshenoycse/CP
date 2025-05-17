#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        ll j=0,n=nums.size(),c=0;
        map<ll,ll> help;
        
        ll ans=(n*n+n)/2ll;
        
        for(ll i=0;i<n;i++){
            c=c+help[nums[i]];
            help[nums[i]]++;
            
            while(j<=i and c>=k){
                c-=(help[nums[j]]-1);
                help[nums[j]]--;
                j++;
            }
            
            ll len=i-j+1;
            ans=ans-len;
        }
        

        return ans;
        
        
    }
};