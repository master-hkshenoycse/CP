#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        set<int> d;
        for(auto e:nums){
            d.insert(e);
        }   

        return d.size()==1?0:1;
    }
};