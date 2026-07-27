#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=0,ma=0;
        for(auto e:nums){
            ans=max(ans,(e-1)*(ma-1));
            ma=max(ma,e);
        }
        return ans;
    }
};