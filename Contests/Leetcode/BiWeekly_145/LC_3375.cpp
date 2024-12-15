#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums[0]<k){
            return -1;
        }   
        set<int> x;
        for(auto e:nums){
            x.insert(e);
        }

        int ans=x.size();
        if(x.find(k) != x.end()){
            ans--;
        }
        return ans;



    }
};