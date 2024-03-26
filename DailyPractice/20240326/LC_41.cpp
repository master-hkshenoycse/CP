#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ll n=nums.size();
        ll j=0;
        //segregating array to negative and positive
        for(int i=0;i<n;i++){
            if(nums[i]<=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }

        ll offset=j;// from j to n-1 there are all positive numbers

        //mark the positive values as negative to mark them as present
        for(ll i=j;i<n;i++){
            if(abs(nums[i])+offset-1<n and nums[abs(nums[i])+offset-1]>0){
                nums[abs(nums[i])+offset-1]*=-1;
            }
        }

        ll ans=1;
        for(ll i=offset;i<n;i++){
            if(nums[i]<0){
                ans++;
            }else{
                return ans;
            }
        }

        return ans;
    }
};