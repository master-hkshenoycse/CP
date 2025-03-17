#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        ll n=candies.size();
        ll ans=0,lo=1,hi=1e9;
        
        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            ll cnt=0;
            
            for(ll i=0;i<n;i++){
                cnt+=candies[i]/mid;
            }
            
            if(cnt>=k){
                ans=max(ans,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        
        return ans;
        
    }
};