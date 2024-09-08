#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        ll n=nums.size();
        vector<ll> nx_gt(n,n);
        stack<ll> st;
        
        for(ll i=n-1;i>=0;i--){
            while(st.size()>0 and nums[i]>=nums[st.top()]){
                st.pop();
            }
            
            if(st.size()>0){
                nx_gt[i]=st.top();
            }
            st.push(i);
        }
        
        ll s=0;
        ll ans=0;
        while(s<n-1){
            int nx=nx_gt[s];
            if(nx>n-1){
                nx=n-1;
            }
            
            ans=ans+nums[s]*(nx-s);
            s=nx;
        }
        
        return ans;
    }
};