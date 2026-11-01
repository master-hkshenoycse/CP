#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int minMoves(vector<int>& nums) {
        ll mi=1e10,n=nums.size(),sum=0;
        for(auto e:nums)
            sum=sum+e,mi=min(mi,e*1ll);
        return sum-mi*n;  
    }
};