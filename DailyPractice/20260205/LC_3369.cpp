#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);

        for(int i=0;i<n;i++){
            int nx_ind=i;
            nx_ind=((i+nums[i])%n+n)%n;
            
            res[i]=nums[nx_ind];
        }

        return res;
    }
};