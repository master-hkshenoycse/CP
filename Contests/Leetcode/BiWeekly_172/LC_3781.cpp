#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        ll n=nums.size(),ans=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(s[i]=='1'){
                ans=ans+pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};