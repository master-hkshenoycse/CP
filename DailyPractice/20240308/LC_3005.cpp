#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> help;
        int r=0;
        for(auto e:nums){
            help[e]++;
            r=max(r,help[e]);
        }
        
        int ans=0;
        for(auto it:help){
            if(it.second==r){
                ans=ans+it.second;
            }
        }
        
        return ans;
    }
};