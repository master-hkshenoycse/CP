#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    
        
        int minimizeMax(vector<int>& nums, int p) {
            sort(nums.begin(),nums.end());
            int lo=0,hi=1e9,ans=hi,n=nums.size();
    
            while(hi>=lo){
                int mid=(hi+lo)/2;
                int cnt=0;
                int i=0;
    
                while(i+1<n){
                    if(nums[i+1]-nums[i]<=mid){
                        cnt++;
                        i+=2;
                    }else{
                        i++;
                    }
                }
    
                if(cnt>=p){
                    ans=min(ans,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
    
            return ans;
        }
    };