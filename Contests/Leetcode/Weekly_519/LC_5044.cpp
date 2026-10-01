#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        ll n=nums.size(),ans=0;
        stack<ll> st;
        map<ll,vector<ll> > help;
        for(ll i=n-1;i>=0;i--){
            while(st.size()>0 && nums[st.top()]>=nums[i])
                st.pop();
            
            ll ind=n;
            if(st.size()>0)
                ind=st.top();
            
            

            ans=ans+ind-i-1;
            //cout<<i<<" "<<ind<<" "<<ans<<endl;
            
            if(help[nums[i]].size()>0){
                auto it=upper_bound(help[nums[i]].begin(),help[nums[i]].end(),-ind);
                int cnt=help[nums[i]].end()-it;
                ans=ans-cnt;
                //cout<<i<<" "<<ind<<" "<<ans<<" "<<cnt<<endl;
            }
            help[nums[i]].push_back(-i);
            st.push(i);
            
        }
        return ans;
    }
};