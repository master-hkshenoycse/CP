#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        ll n=nums.size();
        sort(nums.begin(),nums.end(),[&](int a,int b){
            return abs(a)>abs(b);
        });
        

        ll pos=(n+1)/2;
        ll ans=0,neg=n-pos;

        for(ll i=0;i<n;i++){
            if(i<pos){
                ans=ans+(nums[i]*nums[i]);
            }else{
                ans=ans-(nums[i]*nums[i]);
            }
        }

        return ans;
    }
};