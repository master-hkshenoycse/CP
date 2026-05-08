#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n=nums.size(),bad=0,m_bad=0;
        map<int,int> bad_index,freq;
        for(int i=0;i<n;i++){
            bad+=(nums[i] == forbidden[i]);
            if(nums[i] == forbidden[i])
                bad_index[nums[i]]++,m_bad=max(m_bad,bad_index[nums[i]]);
            freq[nums[i]]++;
            freq[forbidden[i]]++;

        }

        for(auto it:freq)
            if(it.second > n)
                return -1;

        return max((bad+1)/2,m_bad);
        
    }
};