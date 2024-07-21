#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<int> values_pairs(k+1,0);
        int n=nums.size();
        vector<int> max_diff_poss(k+2,0);
        for(int i=0;i<n/2;i++){
            values_pairs[abs(nums[i]-nums[n-i-1])]++;
            int max_poss=max(max(nums[i],nums[n-i-1]),k-min(nums[i],nums[n-i-1]));
            max_diff_poss[max_poss]++;
        }
        
        for(int i=k;i>=0;i--){
            max_diff_poss[i]+=max_diff_poss[i+1];
        }
        
        int ans=INT_MAX;
        for(int i=0;i<=k;i++){
            int one_ops=max_diff_poss[i];
            int two_ops=n/2-one_ops;
            int zero_ops=values_pairs[i];
            one_ops-=zero_ops;
           // cout<<i<<" "<<one_ops<<" "<<two_ops<<endl;
            
            ans=min(ans,one_ops+two_ops*2);
        }
        
        return ans;
        
        
    }
};