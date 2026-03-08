#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        set<int> values(nums.begin(),nums.end());
        vector<int> ret;
        int lo=*values.begin();
        int hi=*(--values.end());
        for(int i=lo;i<=hi;i++){
            if(values.find(i) == values.end())
                ret.push_back(i);
        }

        return ret;
    } 
};