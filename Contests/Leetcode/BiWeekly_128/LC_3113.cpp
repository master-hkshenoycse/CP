#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        ll n=nums.size();

        vector<ll> next_gt(n+1,n);
        stack<ll> st;

        for(ll i=n-1;i>=0;i--){
            while(st.size()>0 and nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.size()>0){
                next_gt[i]=st.top();
            }
            st.push(i);
        }

        map<ll,vector<ll> > help;
        for(ll i=0;i<n;i++){
            help[nums[i]].push_back(i);
        }
        ll ans=0;

        for(ll i=0;i<n;i++){
            ll ind_ele=lower_bound(help[nums[i]].begin(),help[nums[i]].end(),i)-help[nums[i]].begin();
            ll lim=upper_bound(help[nums[i]].begin(),help[nums[i]].end(),next_gt[i]-1)-help[nums[i]].begin();
            lim--;

            //cout<<ind_ele<<" "<<next_gt[i]<<" "<<lim<<endl;

            ans=ans+lim-ind_ele+1;
        }

        return ans;
    }
};