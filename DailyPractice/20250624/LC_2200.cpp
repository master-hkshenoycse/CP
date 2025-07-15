#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
            vector<int> sol;
            int n=nums.size();
            
            for(int i=0;i<n;i++){
                int f=0;
                for(int j=0;j<n;j++){
                    if(nums[j]==key and abs(i-j)<=k){
                        f=1;
                        break;
                    }
                }
                if(f)sol.push_back(i);
            }
            return sol;
        }
    };