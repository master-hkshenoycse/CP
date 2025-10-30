#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref_max(n,0),suff_min(n,0);
        for(int i=0;i<n;i++){
            pref_max[i]=nums[i];
            if(i-1>=0){
                pref_max[i]=max(pref_max[i-1],pref_max[i]);
            }

        }
        for(int i=n-1;i>=0;i--){
            suff_min[i]=nums[i];
            if(i+1<n){
                suff_min[i]=min(suff_min[i+1],suff_min[i]);
            }
        }

        vector<int> ret(n,0);

        for(int i=n-1;i>=0;i--){
            ret[i]=pref_max[i];
            if(i+1<n && suff_min[i+1]<pref_max[i])
                ret[i]=max(ret[i],ret[i+1]);
        }

        return ret;
    }
};