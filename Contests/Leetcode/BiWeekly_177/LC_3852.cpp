#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int,int> freq;
        int mi=1e9;
        for(auto e:nums){
            mi=min(mi,e);
            freq[e]++;
        }
        for(auto it:freq){
            if(it.second != freq[mi]){
                return {mi,it.first};
            }
        }

        return {-1,-1};
    }
};