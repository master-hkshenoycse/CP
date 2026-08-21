#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size();
        long long asc=0,dsc=0;
        int peak=0;

        for(int i=0;i+1<n;i++){
            if(nums[i]<nums[i+1])
                peak=i+1;
        }

        for(int i=0;i<n;i++){
            if(i<=peak)
                asc+=nums[i];
            
            if(i>=peak)
                dsc+=nums[i];
        }

        if(asc>dsc)
            return 0;
        
        if(asc<dsc)
            return 1;
        
        return -1;
        
    }
};