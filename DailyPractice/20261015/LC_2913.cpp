#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0,n=nums.size();
        
        for(int i=0;i<n;i++){
            set<int> x;
            for(int j=i;j<n;j++){
                x.insert(nums[j]);
                ans=ans+x.size()*1*x.size();
            }
        }

        return ans;
        
    }
};