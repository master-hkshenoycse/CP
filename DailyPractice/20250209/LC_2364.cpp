#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ll n=nums.size();
        ll ans=(n*n-n)/2ll;
        
        map<int,int> help;
        for(int i=0;i<n;i++){
            ans=ans-help[i-nums[i]];
            help[i-nums[i]]++;
        }
        
        return ans;
    }
};