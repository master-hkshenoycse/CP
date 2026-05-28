#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int ret=0,n=nums.size();

        for(int i=0;i<n;i++){
            set<int> freq;
            int s=0;
            for(int j=i;j<n;j++){
                s=s+nums[j];
                freq.insert(nums[j]);
                if(freq.find(s) != freq.end())
                    ret++;
            }
        }
        return ret;
        
    
    }
};