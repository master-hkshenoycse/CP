#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n,1),suff(n,1),sol(n,1);
        for(int i=0;i<n;i++){
            pref[i]=pref[i]*nums[i];
            if(i-1>=0)pref[i]=pref[i]*pref[i-1];
        }
        
        for(int i=n-1;i>=0;i--){
            suff[i]=suff[i]*nums[i];
            if(i+1<n)suff[i]=suff[i]*suff[i+1];
        }
        
        for(int i=0;i<n;i++){
            if(i-1>=0)sol[i]=sol[i]*pref[i-1];
            if(i+1<n)sol[i]=sol[i]*suff[i+1];
        }
        
        return sol;
    }
};