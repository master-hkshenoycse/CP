#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for(auto e:nums){
            if(e<k){
                ans++;
            }
        }
        return ans;
    }
};