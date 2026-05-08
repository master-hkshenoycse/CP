#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<vector<int> > val(3);
        for(auto e:nums)
            val[e%3].push_back(e);
        
        for(int i=0;i<3;i++){
            sort(val[i].begin(),val[i].end());
            reverse(val[i].begin(),val[i].end());
        }

        int ans=0;
        if(val[0].size()>=3)
            ans=max(ans,val[0][0]+val[0][1]+val[0][2]);
        
        if(val[1].size()>=3)
            ans=max(ans,val[1][0]+val[1][1]+val[1][2]);
        
        if(val[2].size()>=3)
            ans=max(ans,val[2][0]+val[2][1]+val[2][2]);
        
        if(val[0].size()>0 && val[1].size()>0 && val[2].size()>0)
            ans=max(ans,val[0][0]+val[1][0]+val[2][0]);
        
        return ans;

        
    }
};