#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    
    long long maxSubarraySum(vector<int>& nums, int k) {
        ll ans=-1e18,n=nums.size();   
        ll csum_ops_no=0,csum_ops_run=-1e18,csum_ops_done=-1e18;

        for(ll i=0;i<n;i++){
            ll val=nums[i];
            ll csum_ops_no_tmp=0,csum_ops_run_tmp=0,csum_ops_done_tmp=0;

            csum_ops_no_tmp=max({csum_ops_no+val,val});
            csum_ops_run_tmp=max({csum_ops_run+val*k,csum_ops_no+val*k,val*k});
            csum_ops_done_tmp=max({csum_ops_run+val,csum_ops_done+val});

            csum_ops_no=csum_ops_no_tmp;
            csum_ops_run=csum_ops_run_tmp;
            csum_ops_done=csum_ops_done_tmp;

            //cout<<i<<" "<<csum_ops_no<<" "<<csum_ops_run<<" "<<csum_ops_done<<endl;


            ans=max(ans,csum_ops_run);
            ans=max(ans,csum_ops_done);
        }

        csum_ops_no=0,csum_ops_run=-1e18,csum_ops_done=-1e18;

        for(ll i=0;i<n;i++){
            ll val=nums[i];
            ll csum_ops_no_tmp=0,csum_ops_run_tmp=0,csum_ops_done_tmp=0;

            csum_ops_no_tmp=max({csum_ops_no+val,val});
            csum_ops_run_tmp=max({csum_ops_run+val/k,csum_ops_no+val/k,val/k});
            csum_ops_done_tmp=max({csum_ops_run+val,csum_ops_done+val});

            csum_ops_no=csum_ops_no_tmp;
            csum_ops_run=csum_ops_run_tmp;
            csum_ops_done=csum_ops_done_tmp;


            ans=max(ans,csum_ops_run);
            ans=max(ans,csum_ops_done);
        }




        return ans;



    }
};