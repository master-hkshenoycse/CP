#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        ll n=nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<ll> > cands={{0,1,2},{n-3,n-2,n-1},{0,n-2,n-1},{0,1,n-1}};
        vector<int> poss_vals ={-100000,100000};
        ll ret=-1e18;
        for(auto c:cands){
            for(int i=0;i<3;i++){
                for(int j=0;j<2;j++){
                    ll org=nums[c[i]];
                    nums[c[i]]=poss_vals[j];
                    ret=max(ret,nums[c[0]]*1ll*nums[c[1]]*1ll*nums[c[2]]*1ll);
                    nums[c[i]]=org;
                }
            }
        }

        return ret;
        
    }
};