#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maximumLength(vector<int>& nums, int k) {
            int ans=1;
            for(int i=0;i<k;i++){
                vector<int> dp(k,0);
                for(auto e:nums){
                    
                    int req=(i-e%k+k)%k;
                    dp[e%k]=max(dp[e%k],dp[req]+1);
                    dp[e%k]=max(dp[e%k],1);
                    ans=max(ans,dp[e%k]);
                }
    
                
    
            }
    
            return ans;
        }
    };