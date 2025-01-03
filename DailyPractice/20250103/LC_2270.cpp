#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        ll tot=0,ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            tot=tot+(ll)nums[i];
        }
        
        ll pref=0;
        for(int i=0;i<n-1;i++){
            pref=pref+(ll)nums[i];
            if(pref>=tot-pref)ans++;
        }
        
        
        
        
        return ans;
    }
};