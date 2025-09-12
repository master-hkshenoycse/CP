#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        ll n=nums.size();
        for(ll i=0;i<n;i++){
            if(nums[i] < 0){
                nums[i]=nums[i]*-1;
            }
        }

        sort(nums.begin(),nums.end());

        ll ret=0;
        ll j=0;
        for(ll i=0;i<n;i++){
            while(j<n && nums[j]<=2*nums[i]){
                j++;
            }

            //cout<<i<<" "<<j<<endl;
            ret=ret+(j-i-1);
        }

        return ret;
    }
};