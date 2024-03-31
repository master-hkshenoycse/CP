#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        ll n=nums.size(),i=0;
        ll ans=n;
        while(i<n){
            ll j=i+1,c=1;

            while(j<n and nums[j]!=nums[j-1]){
                j++;
                c++;
            }
            i=j;
            ans=ans+(c*c-c)/2ll;
        }
        return ans;
    }
};