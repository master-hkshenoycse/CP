#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> range_sums;
        for(int i=0;i<n;i++){
            int c_sum=0;
            for(int j=i;j<n;j++){
                c_sum=c_sum+nums[j];
                range_sums.push_back(c_sum);
            }
        }

        int mod=1e9+7,ans=0;
        sort(range_sums.begin(),range_sums.end());
        for(int i=left-1;i<=right-1;i++){
            ans=(ans+range_sums[i])%mod;
        }
        return ans;
    }
};