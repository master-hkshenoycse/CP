#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> tails;

        for (int x : nums) {

            auto it = lower_bound(
                tails.begin(),
                tails.end(),
                x
            );

            if (it == tails.end()) {
                tails.push_back(x);
            } else {
                *it = x;
            }
        }

        return tails.size();
    }
    int longestSubsequence(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<=30;i++){
            vector<int> curr;
            for(auto e:nums){
                if(e & (1<<i))
                    curr.push_back(e);
            }
            ans=max(ans,lengthOfLIS(curr));
        }   
        return ans;
    }
};