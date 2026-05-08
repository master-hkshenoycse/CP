#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int> >help;
        int n=nums.size();

        for(int i=0;i<n;i++){
            help[nums[i]].push_back(i);
        }

        int ans=1e9;
        for(auto it:help){
            int sz=it.second.size();
            for(int i=0;i+2<sz;i++){
                ans=min(ans,2*(it.second[i+2]-it.second[i]));
            }
        }

        if(ans==1e9)
            ans=-1;

        return ans;
    }
};