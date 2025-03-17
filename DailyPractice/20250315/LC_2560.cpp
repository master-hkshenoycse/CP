#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minCapability(vector<int>& nums, int k) {
            int n=nums.size(),lo=0,hi=2e9,ans=2e9;
    
            while(hi>=lo){
                int cnt=0,i=0,mid=(hi+lo)/2;
                while(i<n){
                    if(nums[i] > mid){
                        i++;
                    }else{
                        int c=0,j=i;
                        while(j<n && nums[j]<=mid){
                            j++;
                            c++;
                        }
    
                        i=j;
                        cnt=cnt+(c+1)/2;
    
                    }
    
                }
    
                if(cnt>=k){
                    ans=min(ans,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
                
            }
    
            return ans;
        }
    };