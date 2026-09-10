#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        ll ans=0;
        while(k--){
            ll curr=nums.back();
            nums.pop_back();
            if(mul>0){
                curr=curr*mul;
            }
            mul--;
            ans=ans+curr;
        }
        return ans;
    }
};