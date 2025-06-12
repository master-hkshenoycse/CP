#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll min_diff=1e18,ans=0,cnt=0;
        
        for(auto e:nums){
            ll x=e;
            ll y=(e ^ k);
            
            if(x>y){
                ans=ans+x;
            }else{
                ans=ans+y;
                cnt++;
                
            }            
            min_diff=min(min_diff,abs(x-y));
        }
        
        if(cnt%2){
            ans=ans-min_diff;    
        }
        
        return ans;
    }
};