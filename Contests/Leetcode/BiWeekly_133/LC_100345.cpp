#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(auto e:nums){
            if(e%3){
                ans++;
            }
        }
        
        return ans;
    }
};