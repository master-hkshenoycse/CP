#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maximumUniqueSubarray(vector<int>& nums) {
            int n=nums.size();
            vector<int> csum(n+1,0);
            
            for(int i=1;i<=n;i++){
                csum[i]=nums[i-1];
                csum[i]+=csum[i-1];
            }
            
            map<int,int> help;
            int l=0,ans=0;
            for(int i=1;i<=n;i++){
                l=max(l,help[nums[i-1]]);
                ans=max(ans,csum[i]-csum[l]);
                help[nums[i-1]]=i;
            }
            return ans;
        }
    };