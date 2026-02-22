#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int,int> freq;
        for(auto e:nums){
            freq[e]++;
        }

        int ans=0;
        for(auto it:freq){
            if(it.second%k==0){
                ans=ans+it.second*it.first;
            }
        }

        return ans;
    }
};