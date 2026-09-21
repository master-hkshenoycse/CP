#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<ll> ret(k,0),dp(k,0),tmp(k,0);

        for(auto e:nums){
            for(ll i=0;i<k;i++){
                tmp[i]=0;
            }

            tmp[e%k]++;
            for(ll i=0;i<k;i++){
                tmp[(i*e)%k] = (tmp[(i*e)%k]+dp[i]);
            }

            dp=tmp;
            for(ll i=0;i<k;i++){
                ret[i]=(ret[i]+dp[i]);
            }

        }

        return ret;

    }
};