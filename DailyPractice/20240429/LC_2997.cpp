#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xo=0;
        for(auto e:nums){
            xo=(xo ^ e);
        }
        
        int ans=0;
        for(int i=30;i>=0;i--){
            int a=(k & (1<<i));
            int b=(xo & (1<<i));
            if(a != b){
                ans++;
            }
        }
        
        return ans;
    }
};