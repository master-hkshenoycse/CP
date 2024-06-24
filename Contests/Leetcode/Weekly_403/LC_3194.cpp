#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        double ans=100.0;
        
        for(int i=0;i<n/2;i++){
            ans=min(ans,(nums[i]*1.00+nums[n-i-1]*1.00)/2.00);
        }
        
        return ans;
            
    }
};