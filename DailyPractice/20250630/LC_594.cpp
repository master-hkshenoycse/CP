#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findLHS(vector<int>& nums) {
            map<int,int> help;
            int n=nums.size();
            for(int i=0;i<n;i++)help[nums[i]]++;
            int ans=0;
            
            for(auto v:help) if(help[v.first]>0 and help[v.first+1]>0)ans=max(ans,help[v.first]+help[v.first+1]);
            return ans;
        }
    };