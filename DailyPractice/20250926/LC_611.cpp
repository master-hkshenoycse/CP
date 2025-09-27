#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,j=0,n=nums.size();
        
        vector<int>::iterator it;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                int req=nums[i]+nums[j];
                it=lower_bound(nums.begin(),nums.end(),req);
                it--;
                
                if(req==0 or nums[i]==0 or nums[j]==0){
                    continue;
                }
                
                if(it != nums.end()){
                    ans+=it-(nums.begin()+j);
                }
            }
        }
        
        return ans;
    }
};