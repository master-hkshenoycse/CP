#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_and(vector<vector<int> > &csum,int l,int r){
        int value_and=0;
        for(int j=0;j<32;j++){
            if(csum[j][r]-csum[j][l-1]==r-l+1){
                value_and=value_and+(1<<j);
            }
        }
        return value_and;
    }
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        
        vector<vector<int> > csum(32,vector<int> (n+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<32;j++){
                csum[j][i]=csum[j][i-1];
                if(nums[i-1] & (1<<j)){
                    csum[j][i]++;
                }
            }
        }
        
        int ans=INT_MAX;
        
        for(int i=1;i<=n;i++){
            
            
            int lo=i,hi=n,r=n;
            
            while(hi>=lo){
                int mid=(hi+lo)/2;
                
                
                if(get_and(csum,i,mid)<=k){
                    r=min(r,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            
            ans=min(ans,abs(get_and(csum,i,r) - k));
            
            if(r-1>=i){
                ans=min(ans,abs(get_and(csum,i,r-1) - k));
            }
            
            ans=min(ans,abs(get_and(csum,i,i)-k));
            
            
            
            
            
            
            
        }
        
        
        return ans;
    }
};