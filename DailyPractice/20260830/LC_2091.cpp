#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int ma=-1e9,mi=1e9;
        
        for(int i=0;i<n;i++){
            ma=max(ma,nums[i]);
            mi=min(mi,nums[i]);
        }
        
        int ma_ind=-1,mi_ind=-1;
        
        for(int i=0;i<n;i++){
            if(nums[i]==ma){
                ma_ind=i+1;
            }
            
            if(nums[i]==mi){
                mi_ind=i+1;
            }
        }
        
        if(ma_ind<mi_ind){
            swap(ma_ind,mi_ind);
        }
        
        int ans=ma_ind;
        ans=min(ans,n-mi_ind+1);
        ans=min(ans,n-ma_ind+1+mi_ind);
        return ans;
        
        
        
    }
};