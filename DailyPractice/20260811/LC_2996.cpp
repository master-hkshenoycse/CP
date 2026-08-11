#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        vector<int> cnt(55,0);
        for(auto e:nums){
            cnt[e]++;
        }
        
        int i=1,s=nums[0];
        while(i<nums.size() and nums[i-1]+1==nums[i]){
            s+=nums[i];
            i++;
        }
        
        if(s>50){
            return s;
        }
        
        for(int i=s;i<=51;i++){
            if(cnt[i]==0){
                return i;
            }
        }
        
        return -1;
        
    }
};