#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int specialTriplets(vector<int>& nums) {
            int n=nums.size(),ans=0;
            map<int,int> cnt;
            vector<int> suffix_cnt(n,0);
            int mod=1e9+7;
            for(int i=n-1;i>=0;i--){
                suffix_cnt[i]=cnt[nums[i]*2];
                cnt[nums[i]]++;
            }
    
            cnt.clear();
            for(int i=0;i<n;i++){
                ans=ans+(cnt[nums[i]*2]*1ll*suffix_cnt[i]*1ll)%mod;
                ans%=mod;
                cnt[nums[i]]++;
            }
    
            return ans;
        }
    };