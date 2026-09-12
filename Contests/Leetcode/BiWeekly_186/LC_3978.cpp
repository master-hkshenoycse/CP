#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int cnt=0,n=nums.size();
        for(int i=0;i<n;i++){
            cnt+=(nums[i]==nums[n/2]);
            if(cnt>1)
                return 0;
        }
        return 1;
    }
};