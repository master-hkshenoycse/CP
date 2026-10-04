#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>,int > help;
        int ex=0,n=nums.size(),ans=0;

        for(int i=0;i+1<n;i++){
            if(nums[i] != nums[i+1]){
                help[{nums[i],nums[i+1]}]++;
                help[{nums[i+1],nums[i]}]++;
            }else{
                ans=ans+(nums[i+1]==nums[i]);
            }
        }

        for(auto it:help)
            ex=max(ex,it.second);

        return ans+ex;
    }
};