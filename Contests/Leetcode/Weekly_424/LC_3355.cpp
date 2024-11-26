#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        ll n=nums.size();
        vector<ll> csum(n+2,0);

        for(auto q:queries){
            csum[q[0]]++;
            csum[q[1]+1]--;
        }

        for(int i=1;i<n;i++){
            csum[i]+=csum[i-1];
        }

        for(int i=0;i<n;i++){
            if(csum[i]<nums[i]*1ll){
                return 0;
            }
        }

        return 1;
    }
};