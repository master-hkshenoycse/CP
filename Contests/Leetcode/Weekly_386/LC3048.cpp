#include<bits/stdc++.h>
using namespace std;
/*https://leetcode.com/contest/weekly-contest-386/problems/earliest-second-to-mark-indices-i/*/
class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int m=changeIndices.size();
        int n=nums.size();
        int lo=1,hi=m,ans=m+1;
        
        while(hi>=lo){
            int mid=(hi+lo)/2ll;
            int free_slots=0;
            vector<int> vis(n,0),used(mid,0);
            
            for(int i=mid-1;i>=0;i--){
                if(vis[changeIndices[i]-1]==0){
                    vis[changeIndices[i]-1]=1;
                    used[i]=1;
                }    
            }
            
            int x=0;
            for(int i=0;i<mid;i++){
                if(used[i]==0){
                    free_slots++;
                }else{
                    if(free_slots<nums[changeIndices[i]-1]){
                        break;
                    }
                    x++;
                    free_slots-=nums[changeIndices[i]-1];
                }
                
            }
                
            if(x==n){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        
        if(ans==m+1){
            ans=-1;
        }
        
        return ans;
    }
};