#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ll mi=1e10,ma=-1e10;
        for(auto e:nums){
            mi=min(mi,e*1ll);
            ma=max(ma,e*1ll);
        }

        return (ma-mi)*k*1ll;
    }
};