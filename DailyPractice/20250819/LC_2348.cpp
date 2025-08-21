#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll i=0,ans=0,n=nums.size();
        
        while(i<n){
            if(nums[i] !=0){
                i++;
            }else{
                ll c=0,j=i;
                while(j<n and nums[i]==nums[j]){
                    j++;
                    c++;
                }
                ans=ans+(c*c+c)/2ll;
                i=j;
            }
        }
        
        return ans;
        
        
    }
};