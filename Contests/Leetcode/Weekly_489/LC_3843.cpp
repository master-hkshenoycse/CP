#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int> freq, freq_val, freq_freq;
        for(auto e:nums)
            freq[e]++;
        
        for(auto it:freq)
            freq_freq[it.second]++;
        
        for(auto e:nums){
            if(freq_freq[freq[e]]==1)
                return e;
        }

        return -1;
    }
};