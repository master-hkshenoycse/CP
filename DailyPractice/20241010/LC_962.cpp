#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int> > coll(n,vector<int> (2));
        for(int i=0;i<n;i++){
            coll[i]={nums[i],i};
        }
        sort(coll.begin(),coll.end());
        int ans=0,ind=n;
        for(int i=0;i<n;i++){
            ind=min(ind,coll[i][1]);
            ans=max(ans,coll[i][1]-ind);
        }

        return ans;
    }
};