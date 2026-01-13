#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        ll n=nums.size();
        vector<int> nx_eq_gt(n,n),prev_eq_gt(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size()>0 && nums[st.top()]<nums[i]){
                st.pop();
            }

            if(st.size()>0){
                prev_eq_gt[i]=st.top();
            }

            st.push(i);
        }

        while(st.size()>0){
            st.pop();
        }

        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && nums[st.top()]<nums[i]){
                st.pop();
            }

            if(st.size()>0){
                nx_eq_gt[i]=st.top();
            }

            st.push(i);
        }

        ll ans=0;
        map<int,int> cnt_prev,cnt_nx;

        for(int i=n-1;i>=0;i--){
            if(i+2<n)cnt_prev[prev_eq_gt[i+2]]++;
            ans=ans+cnt_prev[i];
        }

        for(int i=0;i<n;i++){
            if(i-2>=0)cnt_nx[nx_eq_gt[i-2]]++;
            ans=ans+cnt_nx[i];
        }

        return ans;

    }
};