#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> csum(n+2,0);
        
        for(int i=1;i+1<=n;i++){
            if((nums[i-1]+nums[i])%2==0){
                csum[i]=1;
            }else{
                csum[i]=0;
            }
            
            csum[i]+=csum[i-1];
        }
        
        vector<bool> sol;
        
        for(auto q:queries){
            int l=q[0]+1;
            int r=q[1]+1;
            
            bool f=0;
            if(l==r){
                f=1;
            }else{
                if(csum[r-1]-csum[l-1]==0){
                    f=1;
                }
            }
            
            sol.push_back(f);
        }
        
        return sol;
        
    }
};