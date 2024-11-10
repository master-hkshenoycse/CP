#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int> > cnt(n+1,vector<int> (31,0));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=30;j++){
                cnt[i][j]=cnt[i-1][j];
                if(nums[i-1]&(1<<j)){
                    cnt[i][j]++;
                }
            }
        }

        int ans=n+1;
        for(int i=1;i<=n;i++){
            int lo=i,hi=n,req=n+1;

            while(hi>=lo){
                int mid=(hi+lo)/2;

                int value=0;    
                for(int j=0;j<=30;j++){
                    if(cnt[mid][j]-cnt[i-1][j]){
                        value=value+(1<<j);
                    }
                }

                if(value>=k){
                    req=min(req,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            if(req<=n){
                ans=min(ans,req-i+1);
            }
        }
        if(ans==n+1){
            ans=-1;
        }
        return ans;
    }
};