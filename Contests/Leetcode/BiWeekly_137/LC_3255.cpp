#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
          vector<int> sol;
        int i=0,n=nums.size();
        
        while(i<n){
            int j=i+1;
            while(j<n and nums[j]-nums[j-1]==1){
                j++;
            }
            
            for(int p=i;p<j;p++){
                if(p+k-1>=n){
                    continue;
                }
                if(p+k-1<j){
                    sol.push_back(nums[p+k-1]);
                }else{
                    sol.push_back(-1);
                }
            }
            
            i=j;
        }
        
        return sol;
    }
};