#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int largestInteger(vector<int>& nums, int k) {
            map<int,int> help;
            int n=nums.size();
            for(int i=0;i+k-1<n;i++){
                set<int> x;
                for(int j=0;j<k;j++){
                    x.insert(nums[i+j]);
                }
                for(auto e:x){
                    help[e]++;
                }
            }
            int ans=-1;
            for(auto it:help){
                if(it.second == 1){
                    ans=max(ans,it.first);
                }
            }
            return ans;
        }
    };