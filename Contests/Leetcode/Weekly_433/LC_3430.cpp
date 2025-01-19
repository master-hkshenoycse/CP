#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        ll n=nums.size();
        vector<ll> st;
        vector<ll> nx_gt(n,n),prev_gt(n,-1);
        
        for(ll i=0;i<n;i++){
            while(st.size()>0 and  nums[st.back()]<=nums[i]){
                st.pop_back();
            }
            if(st.size()>0){
                prev_gt[i]=st.back();
            }
            st.push_back(i);
        }
        st.clear();
        for(ll i=n-1;i>=0;i--){
            while(st.size()>0 and  nums[st.back()]<nums[i]){
                st.pop_back();
            }
            if(st.size()>0){
                nx_gt[i]=st.back();
            }
            st.push_back(i);
        }
        
        ll ans=0;
        for(ll i=0;i<n;i++){
            ll len_prev=i-prev_gt[i]-1;
            ll len_nx=nx_gt[i]-i-1;
            ll ways=0;

        
            for(ll i=1;i<=min(len_prev,k*1ll-1);i++){
                ll rem=min(k-i-1,len_nx);
                ways=ways+rem;
                if(rem==0){
                    break;
                }
            }
            
            ways+=min(k*1ll-1,len_prev);
            ways+=min(k*1ll-1,len_nx);
            ways++;
            ans=ans+ways*nums[i];
            
//            cout<<i<<" "<<ways<<" "<<len_prev<<" "<<len_nx<<endl;
        }
        
        vector<ll> nx_sm(n,n),prev_sm(n,-1);
        st.clear();
        for(ll i=0;i<n;i++){
            while(st.size()>0 and  nums[st.back()]>=nums[i]){
                st.pop_back();
            }
            if(st.size()>0){
                prev_sm[i]=st.back();
            }
            st.push_back(i);
        }
        
        
        st.clear();
        for(ll i=n-1;i>=0;i--){
            while(st.size()>0 and  nums[st.back()]>nums[i]){
                st.pop_back();
            }
            if(st.size()>0){
                nx_sm[i]=st.back();
            }
            st.push_back(i);
        }
        
        for(ll i=0;i<n;i++){
            ll len_prev=i-prev_sm[i]-1;
            ll len_nx=nx_sm[i]-i-1;
            ll ways=0;

            for(ll i=1;i<=min(len_prev,k*1ll-1);i++){
                ll rem=min(k-i-1,len_nx);
                ways=ways+rem;
                if(rem==0){
                    break;
                }
            }
            
            ways+=min(k*1ll-1,len_prev);
            ways+=min(k*1ll-1,len_nx);
            ways++;
            
            ans=ans+ways*nums[i];
        }
        
        return ans;
        
        
    }
};