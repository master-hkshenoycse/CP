#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
            vector<int> par(n);
            for(int i=0;i<n;i++){
                par[i]=i;
            }
            for(int i=0;i+1<n;i++){
                if(abs(nums[i+1]-nums[i])<=maxDiff){
                    par[i+1]=par[i];
                }
            }
    
            vector<bool> ret;
    
            for(auto q:queries){
                int x = q[0];
                int y= q[1];
    
                ret.push_back(par[x]==par[y]);
            }
    
            return ret;
        }
    };