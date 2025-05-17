#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int get_p10_num(int n){
            int ret=1;
            while(n>0){
                ret=ret*10;
                n/=10;
            }
            return ret;
        }
        vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
            int n=nums.size();
            vector<int> get_p10(n);
    
            for(int i=0;i<n;i++){
               get_p10[i]=get_p10_num(nums[i]);
            }
    
            vector<unordered_map<int,vector<int> > > dp(1<<n);
            dp[0][0]={};
    
            for(int mask=0;mask<(1<<n);mask++){
                for(auto &[rem,seq]:dp[mask]){
                    for(int i=0;i<n;i++){
                        if(mask & (1<<i)){
                            continue;
                        }
                        int n_mask = mask | (1<<i);
                        int n_rem = (rem * get_p10[i]+nums[i])%k;
    
                        vector<int> tmp =seq;
                        tmp.push_back(nums[i]);
    
                        if(dp[n_mask].find(n_rem) == dp[n_mask].end() || tmp<dp[n_mask][n_rem]){
                            dp[n_mask][n_rem] = tmp;
                        }
                    }
                }
            }
    
            vector<int> ret;
            if(dp[(1<<n)-1].count(0)){
                ret = dp[(1<<n)-1][0];
            }
    
            return ret;
        }
    };