#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size(),ans=0;

        map<int,int> help;
        int j=0;
        for(int i=0;i<n;i++){
            help[nums[i]]++;

            while(j<i and help[nums[i]]>k){
                help[nums[j]]--;
                j++;
            }

            ans=max(ans,i-j+1);
        }

        return ans;
    }
};