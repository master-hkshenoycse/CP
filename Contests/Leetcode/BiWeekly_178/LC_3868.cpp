#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> freq_all, freq_1;

        for(auto e:nums1)
            freq_all[e]++,freq_1[e]++;
        
        for(auto e:nums2)
            freq_all[e]++;

        int ans=0;

        for(auto it:freq_all){
            if(it.second%2)
                return -1;
            
            ans=ans+abs((it.second/2)-freq_1[it.first]);
        }
        return ans/2;
    }
};