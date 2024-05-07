#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    ll mod=1e9+7;
    ll get_sol(ll tot_sum,ll min_value,ll max_value,ll req,ll cost1,ll cost2,ll n){
        ll diff=req-min_value;
        ll total_ops=req*n-tot_sum;//total operations required

        if(cost1*2 < cost2){
            //cost2 is only benefical when cost2 is cheaper than 2 cost1 operations
            return total_ops*cost1;
        }

        ll ops_other_min=total_ops-diff;
        if(ops_other_min < diff){//if lowest element required more than half of total operations
            return (ops_other_min)*cost2+(diff-ops_other_min)*cost1;
        }

        return (total_ops/2)*cost2+(total_ops%2)*cost1;
    }
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        ll tot_sum=0;
        ll max_value=-1e9,min_value=1e9;
        ll n=nums.size();
        for(auto e:nums){
            tot_sum+=e;
            max_value=max(max_value,e*1ll);
            min_value=min(min_value,e*1ll);
        }



        ll ans=1e18;
        // the max calue can be max_value to 2*max_value;
        for(ll i=max_value;i<=2*max_value;i++){
            //cout<<i<<" "<<get_sol(tot_sum,min_value,max_value,i,cost1,cost2,n)<<endl;
            ans=min(ans,get_sol(tot_sum,min_value,max_value,i,cost1,cost2,n));
        }       

        return ans%mod;


    }
};